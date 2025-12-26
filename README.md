
# Linux Device Driver Development

## Overview

This repository contains **chapter-wise source code and experiments** developed while studying the book ***Linux Device Drivers* (LDD)** and related Linux kernel driver documentation.

The goal of this repository is **hands-on learning** of Linux kernel internals and device driver development by:

* Writing **minimal, correct, and readable kernel code**
* Understanding **why** things work (not just how)
* Following **upstream Linux coding and documentation practices**

This repository is intended for **educational purposes** and gradual progression from basic kernel modules to real device drivers.

---

## Learning Objectives

* Understand Linux kernel architecture and module loading
* Develop character device drivers
* Learn kernel APIs for memory management, concurrency, and user–kernel interaction
* Gain confidence reading and navigating Linux kernel source code
* Build documentation habits aligned with upstream Linux standards


### 📁 `chapterXX/`

Each chapter directory contains:

* Kernel module or driver source code
* A minimal `Makefile` using Kbuild
* Code written and tested against a modern Linux kernel (LTS)

---

##  Build & Run Instructions

### Prerequisites

* Linux system (Tested on Ubuntu )
* Matching kernel headers installed

```bash
sudo apt install build-essential linux-headers-$(uname -r)
```

### Build a Module

```bash
cd chapter01
make
```

### Load the Module

```bash
sudo insmod hello_module.ko
```

### Verify

```bash
dmesg | tail
lsmod | grep hello
```

### Remove the Module

```bash
sudo rmmod hello_module
```

---

## References

* **Linux Device Drivers**, Jonathan Corbet, Alessandro Rubini, Greg Kroah-Hartman
* Linux Kernel Documentation
  [https://docs.kernel.org/](https://docs.kernel.org/)
* Linux Kernel Source
  [https://elixir.bootlin.com/linux/latest/source](https://elixir.bootlin.com/linux/latest/source)

---

## Disclaimer

* This code is for **learning and experimentation only**
* Not intended for production systems
* Loading kernel modules can **crash or hang your system**
* Use inside a **VM or test machine** whenever possible

---

## Notes & Best Practices

* Code style follows Linux kernel conventions where applicable
* Kernel logging uses appropriate `pr_info`, `pr_err`, etc.
* Unsafe shortcuts are **intentionally avoided** to build correct habits
* Each chapter builds on concepts from previous ones

---

## License

This project is licensed under the **MIT License** – see the `LICENSE` file for details.

---


