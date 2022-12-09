# eebs
A program to connect LEFT and SMEFT. One can compile codes by running **make**. 

This will generate two executable:
```
main1 -- read SMEFT input and run parameters from UV scale to Low scale. Matching scale is set to EW scale. 
main2 -- read LEFT input and run parameters from Low scale to UV scale. Matching scale is set to EW scale.
```

Input files are: 
```
input_SM.txt -- give the UV scale, EW scale, and Low scale, and the necessary Standard Model parameters.
input_SMEFT.txt -- give the SMEFT input.
input_LEFT.txt -- give the LEFT input.
```
