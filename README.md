# Welcome!

This repo is my attempt to **dive deeper into parallel computing** and to serve as **personal documentation** for myself (corresponding Notion page is pending!). I will be covering (in order) `OpenCL`, `CUDA`, and `Metal` on **macOS** and **Windows**.

# OpenCL

At this point, I am getting a simple `OpenCL` progam to run on *macOS with an M-Series chip*, trying to understand everything from:

- All that is needed to properly **compile** (`Makefile`, dependencies, etc)
- Best ways to **allocate memory** (espeicially for `tiling`)
- Good practices for **memory access** (bursting/banking)

As for more complicated programs, I plan to update my [Ray Tracer](https://github.com/jphung101/Ray-Tracer) to support `OpenCL`

# OpenMP

Figured while I am busy to try something "simpler" like `OpenMP`. Might regret this...
- Ran `brew install libomp`
- Agreed to XCode license `sudo xcodebuild -license`

# CUDA

*No access to Nvidia GPU, yet*

# Metal
## "PyTorch"
- Used `PyTorch`'s built in functions to set the processing unit to `Metal Performance Shaders (MPS)` when available.
- Most of the code is from UCSD's [ECE 284: Low-power VLSI Implementation for Machine Learning](https://github.com/VVIPLab/ece284fa25/tree/main), I simply added `MPS` support and removed some stuff
- Tested 100 epochs:
    - `CPU:` 4m 59.3s
        - ![CPU (4m 59.3s)](Media/PyTorchCPU.png)
    - `MPS:` 50.3s
        - ![MPS (50.3s)](Media/PyTorchMPS.png)
        - Very simple, but it was really cool to see the GPU actually getting used!
- TODO: Custom loss function