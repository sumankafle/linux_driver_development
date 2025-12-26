## Chapter 02 – Hello World Kernel Modules

This chapter introduces the **basic structure of Linux kernel modules** using simple “Hello World” examples.
The focus is on **building multiple modules**, **loading/unloading**, and **passing parameters** using a unified Makefile.

---

## Build System (Makefile)

The provided Makefile builds **two kernel modules** and includes a convenient `test` target to automatically load, unload, and inspect kernel logs.

### Supported Targets

```bash
make        # Build all kernel modules
make clean  # Clean build artifacts
make test   # Build and test both modules (with optional parameters)
```

---

## Modules Built

After running `make`, the following kernel modules are produced:

* `helloworld.ko`
* `helloworld_params.ko`

### `helloworld.ko`

A minimal kernel module that prints log messages when:

* the module is loaded
* the module is unloaded

### `helloworld_params.ko`

An extended kernel module that demonstrates:

* module parameters (`int`, `string`, and `array`)
* passing parameters at load time
* printing parameter values to the kernel log

---

## Quick Test (Recommended)

The easiest way to test both modules is:

```bash
make test
```

This will:

1. Clear the kernel log
2. Load and unload `helloworld.ko`
3. Load and unload `helloworld_params.ko`
4. Display the latest kernel log output

---

## Testing With Parameters

You can pass parameters to `helloworld_params.ko` directly via the Makefile:

```bash
make test PARAMS="myint=42 mystr=Hi myarr=5,6,7"
```

This internally runs:

```bash
sudo insmod helloworld_params.ko myint=42 mystr=Hi myarr=5,6,7
```

---

## Manual Loading (Optional)

### Load the basic module

```bash
sudo insmod helloworld.ko
sudo rmmod helloworld.ko
dmesg
```

Expected output:

```text
[xxxx.xxxxxx] Hello World!
[xxxx.xxxxxx] End of the world
```

---

### Load the parameterized module (default values)

```bash
sudo insmod helloworld_params.ko
sudo rmmod helloworld_params.ko
dmesg
```

Expected output:

```text
[xxxx.xxxxxx] Hello World with parameters!
[xxxx.xxxxxx] Name: hello
[xxxx.xxxxxx] Integer value: 1
[xxxx.xxxxxx] Array values: 0, 1, 2
[xxxx.xxxxxx] End of the world
```

---

### Load the parameterized module (custom values)

```bash
sudo insmod helloworld_params.ko mystr="packtpub" myint=255 myarr=23,4,7
sudo rmmod helloworld_params.ko
dmesg
```

Expected output:

```text
[xxxx.xxxxxx] Hello World with parameters!
[xxxx.xxxxxx] Name: packtpub
[xxxx.xxxxxx] Integer value: 255
[xxxx.xxxxxx] Array values: 23, 4, 7
[xxxx.xxxxxx] End of the world
```

---


