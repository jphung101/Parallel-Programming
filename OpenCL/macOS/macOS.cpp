// This file is an attempt to get OpenCL working on an ARM Mac (specifically M1)
#include <iostream>
#include <string>
#include <OpenCL/cl.h>
#include <time.h> // for timing

using namespace std;

void check(cl_int err);


int main(int argc, char *argv[]){
    cl_int err; // used to catch errors
    cl_platform_id platforms; // not needed, as we only have 1 platform (?). Not exactly sure what multiple platforms entail

    int num = 1; // number of devices you expect your platform to have
    cl_device_id device;
    cl_device_id devices[num]; // holds CPU/GPU options
    cl_uint deviceCount; // number of devices that are availble 

    // DEVICE ID:
    err = clGetDeviceIDs(nullptr, CL_DEVICE_TYPE_ALL, num, devices, &deviceCount);
    printf("Device count: %d\n", deviceCount); // Considered `CL_DEVICE_TYPE_GPU`
    check(err);

    if(num == 1 || argc == 1){
        device = devices[0];
    }else{
        device = devices[stoi(argv[1])];
    }

    // DEVICE INFO:
    string name;
    err = clGetDeviceInfo(device, CL_DEVICE_NAME, sizeof(name), &name, nullptr);
    printf("Device name: %s\n", name.c_str());
    check(err);

    // CONTEXT:
    cl_context context;
    context = clCreateContext(nullptr, 1, &device, nullptr, nullptr, &err);
    check(err);

    // COMMAND QUEUE:
    cl_command_queue queue;
    #if __APPLE__
        queue = clCreateCommandQueue(context, device, 0, &err); // TODO: figure out what the "0" is
    #else 
        queue = clCreateCommandQueueWithProperties(context, device, 0, &err);
    #endif
    check(err);

    



    return 0;
}

void check(cl_int err){
    if(err != CL_SUCCESS){
        printf("Error: %d\n", err);
    }
}