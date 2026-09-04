fix_rgbdsensorclient_stamp_race {#yarp_3_12}
-----------

### devices

#### `RGBDSensorClient`

* Fixed a race condition in `RGBDSensor_StreamingMsgParser::read()` that could
  cause a segmentation fault. The method retrieved the image timestamps by
  calling `port_rgb->getEnvelope()` / `port_depth->getEnvelope()` from the
  caller's thread, outside the mutex that protects the buffered frames.
  `PortReaderBufferBase::getEnvelope()` reads the `prev` packet pointer without
  holding `stateMutex`, so the port's own reader thread could recycle that
  packet between the null check and the dereference of `prev->envelope`,
  leading to a use-after-free. The stamps are now taken from the snapshot
  already returned by `getImage()` under the lock, consistently with what
  `readRgb()` and `readDepth()` do.

  This also fixes a latent correctness issue: the envelope returned by
  `getEnvelope()` belonged to the most recently received frame, which is not
  necessarily the frame returned by the same call, so images and timestamps
  could be mismatched.
