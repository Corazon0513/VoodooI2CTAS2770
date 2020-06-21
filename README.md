# TI TAS2770智能功放芯片驱动

---

本项目基于Alexandre的VoodooI2C框架。

参考了Linux5.7内核代码包含的TAS2770驱动。

旨在解决联想Y9000X及类似使用了TI TAS系列智能功放芯片的设备在Linux/macOS(Hackintosh)下外放无声的问题。

---

## 请注意：短期内该设备被驱动的可能性较小，原因请参考[issue-1](https://github.com/Corazon0513/VoodooI2CTAS2770/issues/1)。

---

已知联想拯救者Y9000X的TAS2770的I2C地址为：左0x84, 右0x82

作者：[@Corazon](https://github.com/Corazon0513/)
