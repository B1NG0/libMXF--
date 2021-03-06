/*
 * $Id: GenericDescriptorBase.cpp,v 1.2 2009/04/16 17:52:50 john_f Exp $
 *
 *
 *
 * Copyright (C) 2008  Philip de Nier <philipn@users.sourceforge.net>
 *
 * This library is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Lesser General Public
 * License as published by the Free Software Foundation; either
 * version 2.1 of the License, or (at your option) any later version.
 *
 * This library is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public
 * License along with this library; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301  USA
 */

#include <libMXF++/MXF.h>
#include <memory>


using namespace std;
using namespace mxfpp;


const mxfKey GenericDescriptorBase::setKey = MXF_SET_K(GenericDescriptor);


GenericDescriptorBase::GenericDescriptorBase(HeaderMetadata* headerMetadata)
: InterchangeObject(headerMetadata, headerMetadata->createCSet(&setKey))
{
    headerMetadata->add(this);
}

GenericDescriptorBase::GenericDescriptorBase(HeaderMetadata* headerMetadata, ::MXFMetadataSet* cMetadataSet)
: InterchangeObject(headerMetadata, cMetadataSet)
{}

GenericDescriptorBase::~GenericDescriptorBase()
{}


bool GenericDescriptorBase::haveLocators() const
{
    return haveItem(&MXF_ITEM_K(GenericDescriptor, Locators));
}

std::vector<Locator*> GenericDescriptorBase::getLocators() const
{
    vector<Locator*> result;
    auto_ptr<ObjectIterator> iter(getStrongRefArrayItem(&MXF_ITEM_K(GenericDescriptor, Locators)));
    while (iter->next())
    {
        MXFPP_CHECK(dynamic_cast<Locator*>(iter->get()) != 0);
        result.push_back(dynamic_cast<Locator*>(iter->get()));
    }
    return result;
}

void GenericDescriptorBase::setLocators(const std::vector<Locator*>& value)
{
    WrapObjectVectorIterator<Locator> iter(value);
    setStrongRefArrayItem(&MXF_ITEM_K(GenericDescriptor, Locators), &iter);
}

void GenericDescriptorBase::appendLocators(Locator* value)
{
    appendStrongRefArrayItem(&MXF_ITEM_K(GenericDescriptor, Locators), value);
}

