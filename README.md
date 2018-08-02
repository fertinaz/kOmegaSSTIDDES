# kOmegaSSTIDDES
k-omega SST IDDES model adapted to OF-5.0 version

Installation:
---------------
01- Create $WM_PROJECT_USER_DIR/src under the OpenFOAM directory 
    and extract the TurbulenceModels.tar.gz into this folder.

02- Tarball basically includes OpenFOAM-5.0/src/TurbulenceModels directory with its subfolders. 
    It also contains two new models kOmegaSSTDDES and kOmegaSSTIDDES 
    inside TurbulenceModels/turbulenceModels/LES

03- Initially you need to compile the entire TurbulenceModels directory 
    EXCLUDING kOmegaSSTDDES and kOmegaSSTIDDES.
    So move them somewhere else temporarily before you start compiling.

04- Also, before running TurbulenceModels/Allwmake open
    TurbulenceModels/incompressible/turbulentTransportModels/turbulentTransportModels.C
    and comment-out parts related to kOmegaSSTDDES and kOmegaSSTIDDES.

05- Run TurbulenceModels/Allwmake. 
    This will compile all turbulence models and write .so files to $FOAM_USER_LIBBIN

06- Now we should add kOmegaSSTDDES and kOmegaSSTIDDES to compilation.

07- Move back kOmegaSSTDDES and kOmegaSSTIDDES to their location in 
    TurbulenceModels/turbulenceModels/LES

08- Add compilation macros back in the file 
    TurbulenceModels/incompressible/turbulentTransportModels/turbulentTransportModels.C
    for kOmegaSSTDDES and kOmegaSSTIDDES

09- Run wmakeLnInclude -u turbulenceModels

10- Run TurbulenceModels/Allwmake again.

11- It will not write that it compiles kOmegaSSTDDES and kOmegaSSTIDD explicitly that it does.
    You can assume they are compiled successfully unless it fails with an error. 
 
12- Create $WM_PROJECT_USER_DIR/run directory and extract
    motorBike_kOmegaSST_IDDES.tar.gz and then see Allrun file in it.
