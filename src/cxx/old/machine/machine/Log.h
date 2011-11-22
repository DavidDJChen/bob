/**
 * @file cxx/old/machine/machine/Log.h
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
#ifndef _TORCH5SPRO_LOG_MACHINE_H_
#define _TORCH5SPRO_LOG_MACHINE_H_

#include "machine/GradientMachine.h"	// Log is a <GradientMachine>
#include "machine/Machines.h"

namespace Torch
{
        //////////////////////////////////////////////////////////////////////////////////////
	// Torch::Log:
	//
	// TODO: doxygen header!
	//////////////////////////////////////////////////////////////////////////////////////

	class Log : public GradientMachine
	{
	public:

		/// Constructor
		Log();

		Log(const int n_units_);

		/// Destructor
		virtual ~Log();

		///////////////////////////////////////////////////////////

		virtual bool 		forward(const DoubleTensor *input);

		virtual bool 		backward(const DoubleTensor *input, const DoubleTensor *alpha);

		/// Constructs an empty Machine of this kind - overriden
		// (used by <MachineManager>, this object should be deallocated by the user)
		virtual Machine*	getAnInstance() const { return new Log(); }

		// Get the ID specific to each Machine - overriden
		virtual int		getID() const { return LOG_GRADIENT_MACHINE_ID; }

		///////////////////////////////////////////////////////////

	};

        // !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
        // REGISTER this machine to the <MachineManager>
        const bool log_gradient_machine_registered = MachineManager::getInstance().add(new Log(), "Log");
        // !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
}

#endif
