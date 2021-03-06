/*---------------------------------------------------------------------------*\
  =========                 |
  \\      /  F ield         | OpenFOAM: The Open Source CFD Toolbox
   \\    /   O peration     |
    \\  /    A nd           | Copyright (C) 2015-2018 OpenFOAM Foundation
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

\*---------------------------------------------------------------------------*/

#include "addToRunTimeSelectionTable.H"

#include "phaseSystem.H"
#include "twoPhaseSystem.H"
#include "MomentumTransferPhaseSystem.H"
#include "HeatTransferPhaseSystem.H"
#include "HeatAndMassTransferPhaseSystem.H"
#include "PopulationBalancePhaseSystem.H"
#include "InterfaceCompositionPhaseChangePhaseSystem.H"
#include "ThermalPhaseChangePhaseSystem.H"

// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

namespace Foam
{
    typedef
        HeatTransferPhaseSystem
        <
            MomentumTransferPhaseSystem<twoPhaseSystem>
        >
        heatAndMomentumTransferTwoPhaseSystem;

    addNamedToRunTimeSelectionTable
    (
        twoPhaseSystem,
        heatAndMomentumTransferTwoPhaseSystem,
        dictionary,
        heatAndMomentumTransferTwoPhaseSystem
    );

    typedef
        HeatAndMassTransferPhaseSystem
        <
            MomentumTransferPhaseSystem<twoPhaseSystem>
        >
        heatAndMassTransferTwoPhaseSystem;

    addNamedToRunTimeSelectionTable
    (
        twoPhaseSystem,
        heatAndMassTransferTwoPhaseSystem,
        dictionary,
        heatAndMassTransferTwoPhaseSystem
    );

    typedef
        InterfaceCompositionPhaseChangePhaseSystem
        <
            HeatAndMassTransferPhaseSystem
            <
                MomentumTransferPhaseSystem<twoPhaseSystem>
            >
        >
        interfaceCompositionPhaseChangeTwoPhaseSystem;

    addNamedToRunTimeSelectionTable
    (
        twoPhaseSystem,
        interfaceCompositionPhaseChangeTwoPhaseSystem,
        dictionary,
        interfaceCompositionPhaseChangeTwoPhaseSystem
    );

    typedef
        ThermalPhaseChangePhaseSystem
        <
        HeatAndMassTransferPhaseSystem
        <
            MomentumTransferPhaseSystem<twoPhaseSystem>
        >
        >
        thermalPhaseChangeTwoPhaseSystem;

    addNamedToRunTimeSelectionTable
    (
        twoPhaseSystem,
        thermalPhaseChangeTwoPhaseSystem,
        dictionary,
        thermalPhaseChangeTwoPhaseSystem
    );

    typedef
        PopulationBalancePhaseSystem
        <
            HeatAndMassTransferPhaseSystem
            <
                MomentumTransferPhaseSystem<twoPhaseSystem>
            >
        >
        populationBalanceTwoPhaseSystem;

    addNamedToRunTimeSelectionTable
    (
        twoPhaseSystem,
        populationBalanceTwoPhaseSystem,
        dictionary,
        populationBalanceTwoPhaseSystem
    );

    typedef
        ThermalPhaseChangePhaseSystem
        <
            PopulationBalancePhaseSystem
            <
                HeatAndMassTransferPhaseSystem
                <
                    MomentumTransferPhaseSystem<twoPhaseSystem>
                >
            >
        >
        thermalPhaseChangePopulationBalanceTwoPhaseSystem;

        addNamedToRunTimeSelectionTable
        (
            twoPhaseSystem,
            thermalPhaseChangePopulationBalanceTwoPhaseSystem,
            dictionary,
            thermalPhaseChangePopulationBalanceTwoPhaseSystem
        );
}


// ************************************************************************* //
