# A Kernel Seedling

This documentation describes the `proc_count` kernel module, which introduces a `/proc/count` file. Reading this file returns the current number of running processes on a Linux system. Below are instructions for building, running, cleanning up, and testing this module.

## Building

To build the `proc_count` module, navigate to the directory containing the source code and Makefile, then run:

```shell
make
```

This command will compile the `proc_count.c` file and generate a `proc_count.ko` kernel object file suitable for insertion into the kernel.

## Running

To insert the module into the kernel and create the `/proc/count` file, run:

```shell
sudo insmod proc_count.ko
```

Upon successful insertion, to demonstrate the content inside `/proc/count`, run:

```shell
cat /proc/count
```

The output should be a single integer value shows the current number of running processes.

**Note**:  This count (the number of running processes) can fluctuate as processes start and stop, so it's expected that the output from `/proc/count` might vary between consecutive reads.

## Cleaning Up

To remove the kernel module while the module is completed or is needed to recompile and reinsert, run:

```shell
sudo rmmod proc_count
```

## Testing

```python
python -m unittest
```

### Expected Results

The test cases should pass without any errors, indicating the module is correctly counting the running processes and exposing this count through the `/proc/count` file. After testing, the keyword **OK** will be printed which represents the success.

## Kernel Version

Report which kernel release version you tested your module on
(hint: use `uname`, check for options with `man uname`).
It should match release numbers as seen on https://www.kernel.org/.

```shell
uname -r -s -v
```

After the preceding command is executed on the provided virtual machine, the following text is showed:

```
Linux 5.14.8-arch1-1 #1 SMP PREEMPT Sun, 26 Sep 2021, 19:36:15 +0000
```

