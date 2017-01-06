/* ***** BEGIN LICENSE BLOCK *****
 * This file is part of Natron <http://www.natron.fr/>,
 * Copyright (C) 2013-2017 INRIA and Alexandre Gauthier-Foichat
 *
 * Natron is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * Natron is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with Natron.  If not, see <http://www.gnu.org/licenses/gpl-2.0.html>
 * ***** END LICENSE BLOCK ***** */

#ifndef IMAGEKEY_H
#define IMAGEKEY_H

// ***** BEGIN PYTHON BLOCK *****
// from <https://docs.python.org/3/c-api/intro.html#include-files>:
// "Since Python may define some pre-processor definitions which affect the standard headers on some systems, you must include Python.h before any standard headers are included."
#include <Python.h>
// ***** END PYTHON BLOCK *****

#include "Global/Macros.h"

#include "Engine/KeyHelper.h"
#include "Engine/ViewIdx.h"
#include "Engine/EngineFwd.h"

#include "Serialization/ImageKeySerialization.h"

NATRON_NAMESPACE_ENTER;

class ImageKey
    : public KeyHelper<U64>
    , public SERIALIZATION_NAMESPACE::SerializableObjectBase
{
public:

    typedef SERIALIZATION_NAMESPACE::ImageKeySerialization SerializationType;

    U64 _nodeHashKey;
    double _time;
    ViewIdx _view; 
    bool _draftMode;



    ImageKey();

    ImageKey(const std::string& pluginID,
             U64 nodeHashKey,
             double time,
             ViewIdx view,
             bool draftMode);

    virtual void fillHash(Hash64* hash) const OVERRIDE FINAL;

    U64 getTreeVersion() const
    {
        return _nodeHashKey;
    }

    bool operator==(const ImageKey & other) const;

    double getTime() const
    {
        return _time;
    }

    ViewIdx getView() const
    {
        return _view;
    }

    virtual void toSerialization(SERIALIZATION_NAMESPACE::SerializationObjectBase* serializationBase) OVERRIDE FINAL;

    virtual void fromSerialization(const SERIALIZATION_NAMESPACE::SerializationObjectBase& serializationBase) OVERRIDE FINAL;
};

NATRON_NAMESPACE_EXIT;

#endif // IMAGEKEY_H
