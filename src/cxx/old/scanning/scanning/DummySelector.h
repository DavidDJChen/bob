/**
 * @file cxx/old/scanning/scanning/DummySelector.h
 * @date Wed Apr 6 14:49:40 2011 +0200
 * @author Andre Anjos <andre.anjos@idiap.ch>
 *
 * Copyright (C) 2011 Idiap Reasearch Institute, Martigny, Switzerland
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, version 3 of the License.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */
#ifndef _TORCHVISION_SCANNING_DUMMY_SELECTOR_H_
#define _TORCHVISION_SCANNING_DUMMY_SELECTOR_H_

#include "scanning/Selector.h"		// <DummySelector> is a <Selector>

namespace Torch
{
   	/////////////////////////////////////////////////////////////////////////
	// Torch::Scanning::DummySelector
	//	- just for testing purposes
	//
	// TODO: doxygen header!
	/////////////////////////////////////////////////////////////////////////

	class DummySelector : public Selector
	{
	public:

		// Constructor
		DummySelector();

		// Destructor
		virtual ~DummySelector();

		// Delete all stored patterns
		virtual void			clear();

		// Process the list of candidate sub-windows and select the best ones
		// (this will accumulate them to the pattern list)
		virtual bool			process(const PatternList& candidates);

	protected:

		/////////////////////////////////////////////////////////////////
		// Attributes

		//
	};
}

#endif
