/*---------------------------------------------------------------------------*\
  =========                 |
  \\      /  F ield         | OpenFOAM: The Open Source CFD Toolbox
   \\    /   O peration     |
    \\  /    A nd           | Copyright (C) 2016 OpenFOAM Foundation
     \\/     M anipulation  |
-------------------------------------------------------------------------------
License
    This file is part of OpenFOAM.

    OpenFOAM is free software: you can redistribute it and/or modify it
    under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    OpenFOAM is distributed in the hope that it will be useful, but WITHOUT
    ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or
    FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License
    for more details.

    You should have received a copy of the GNU General Public License
    along with OpenFOAM.  If not, see <http://www.gnu.org/licenses/>.

Class
    Foam::LESModels::kOmegaSST

Description
    Implementation of the k-omega-SST-IDDES turbulence model for
    incompressible and compressible flows.

    Based on the model implementation in OF-1712
    Fatih Ertinaz

Group
    // grpLESTurbulence

See also
    Foam::kOmegaSST

SourceFiles
    kOmegaSSTIDDES.C

\*---------------------------------------------------------------------------*/

#ifndef kOmegaSSTIDDES_H
#define kOmegaSSTIDDES_H

#include "kOmegaSSTDES.H"
#include "IDDESDelta.H"

// #include "LESModel.H"
// #include "LESeddyViscosity.H"

// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

namespace Foam
{
namespace LESModels
{

/*---------------------------------------------------------------------------*\
                          Class kOmegaSST Declaration
\*---------------------------------------------------------------------------*/

template<class BasicTurbulenceModel>
class kOmegaSSTIDDES
:
    public kOmegaSSTDES<BasicTurbulenceModel>    
{
    // Private data
    
        // Model constants
            dimensionedScalar Cdt1_;
            dimensionedScalar Cdt2_;
            dimensionedScalar Cl_;
            dimensionedScalar Ct_;
    
        // Fields
            const IDDESDelta& IDDESDelta_;
    
        // Private Member Functions
            // const IDDESDelta& setDelta() const;

            tmp<volScalarField> alpha() const;
            tmp<volScalarField> ft(const volScalarField& magGradU) const;
            tmp<volScalarField> fl(const volScalarField& magGradU) const;

            tmp<volScalarField> rd
            (
                const volScalarField& nur,
                const volScalarField& magGradU
            ) const;

            //- Delay function
            tmp<volScalarField> fdt(const volScalarField& magGradU) const;

            // Disallow default bitwise copy construct and assignment
            kOmegaSSTIDDES(const kOmegaSSTIDDES&);
            void operator=(const kOmegaSSTIDDES&);

protected:

    // Protected Member Functions

        //- Length scale
        virtual tmp<volScalarField> dTilda
        (
            const volScalarField& magGradU,
            const volScalarField& CDES
        ) const;
        
public:

    typedef typename BasicTurbulenceModel::alphaField alphaField;
    typedef typename BasicTurbulenceModel::rhoField rhoField;
    typedef typename BasicTurbulenceModel::transportModel transportModel;


    //- Runtime type information
    TypeName("kOmegaSSTIDDES");


    // Constructors

        //- Construct from components
        kOmegaSSTIDDES
        (
            const alphaField& alpha,
            const rhoField& rho,
            const volVectorField& U,
            const surfaceScalarField& alphaRhoPhi,
            const surfaceScalarField& phi,
            const transportModel& transport,
            const word& propertiesName = turbulenceModel::propertiesName,
            const word& type = typeName
        );


    //- Destructor
    virtual ~kOmegaSSTIDDES()
    {}


    // Member Functions

        //- Read model coefficients if they have changed
        virtual bool read();
};


// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

} // End namespace LESModels
} // End namespace Foam

// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //
#ifdef NoRepository
    #include "kOmegaSSTIDDES.C"
#endif

// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //
#endif

// ************************************************************************* //
