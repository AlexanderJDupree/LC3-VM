# LC3-VM

## Introduction

**LC3-VM** is a virtual machine implementation of the *Little Computer 3* assembly language. The specification for **LC3** can be found [here](https://justinmeiners.github.io/lc3-vm/supplies/lc3-isa.pdf). As of right now, all instructions and trap 
codes are implemented except *RTI* and *RES*.

## Getting Started

Download the repo:

```bash
git clone https://github.com/AlexanderJDupree/LC3-VM.git
```

Build and Install
```
cmake --build build --target install -- -j 6
```

Run the VM! 
```
./bin/lc3 [image-files] ...
```

I have provided two images in this repo `2048.obj` and `rogue.obj` you can 
run either of those games like this:

```
./bin/lc3 2048.obj
```

## Thanks

* [justinmeiners](https://github.com/justinmeiners/lc3-vm) - LC3 Tutorial and Inspiration

## License

This project is licensed under the MIT License - see the [LICENSE.md](https://raw.githubusercontent.com/AlexanderJDupree/lc3-virtual-machine/master/LICENSE) file for details
