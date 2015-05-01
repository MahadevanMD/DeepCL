// Copyright Hugh Perkins 2015 hughperkins at gmail
//
// This Source Code Form is subject to the terms of the Mozilla Public License, 
// v. 2.0. If a copy of the MPL was not distributed with this file, You can 
// obtain one at http://mozilla.org/MPL/2.0/.

#pragma once

#include <stdexcept>
#include <string>
#include <iostream>
#include <algorithm>

#include "TrainerState.h"

class EasyCL;
class CLKernel;

#include "DeepCLDllExport.h"

#define VIRTUAL virtual
#define STATIC static

// Stochastic gradient descent
// learning rate, momentum, maybe annealing
// maybe each layer gets its own TrainerState object?
// at least: any layer with weights
// they could all be initialized with the same values
// but still, they each get their own object
// we could always make like a 'prototype' or 'factory'
// object that then gets passed to each weightful layer
// Maybe a 'Maker' for trainers?
class DeepCL_EXPORT SGDState : public TrainerState {
public:
//    EasyCL *cl;
//    CLKernel *kernel;

    const int numWeights;

//    float learningRate;
//    float momentum;

    // should store last weights
    float *lastUpdate;
    CLWrapper *lastUpdateWrapper;

    // [[[cog
    // import cog_addheaders
    // cog_addheaders.add()
    // ]]]
    // generated, using cog:
    VIRTUAL ~SGDState();
    VIRTUAL void updateWeights(CLWrapper *gradientsWrapper, CLWrapper *weightsWrapper );
    SGDState( EasyCL *cl, int numWeights );

    // [[[end]]]
};
