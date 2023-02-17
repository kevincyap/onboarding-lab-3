# Week 3 Lab: Verification

Had to run ```sudo apt-get install pkg-config```

What testing strategy did you adopt for this Exercise2? What decisions did you have to make and how did you come up with your answers?
I started with an arbitrary number which runs the LFSR for many cycles. Due to the function of the LFSR, simply testing one number for multiple cycles can guarantee with reasonable certainty that the module functions properly.

How does testing a Don't Care work? What must be done to ensure the input truly has no effect on output?
I tested very possible value for the Don't Care variable. This is to make sure that the Don't Care variable actually doesn't affect the output.