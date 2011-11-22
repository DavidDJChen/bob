/**
 * @file cxx/core/core/Parameters.h
 * @date Tue Jan 18 17:07:26 2011 +0100
 * @author André Anjos <andre.anjos@idiap.ch>
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
#ifndef _TORCH5SPRO_PARAMETERS_H_
#define _TORCH5SPRO_PARAMETERS_H_

#include "core/Object.h"
#include "core/File.h"

namespace Torch
{
	/** Parameter class

	    @author Sebastien Marcel
	*/
	class Parameters : public Object
	{
	public:

		/// Constructor
		Parameters();

	    	/// Destructor
	    	virtual ~Parameters();

		///////////////////////////////////////////////////////////
		/// Parameters management functions - adding new ones

		/// returns \c false if the name is already taken
		bool			addI(const char* name, const int init_value = 0, const char* help = "");
		bool			addF(const char* name, const float init_value = 0, const char* help = "");
		bool			addD(const char* name, const double init_value = 0, const char* help = "");
		bool			addIarray(const char* name, const int n_values = 0, const int init_value = 0, const char* help = "");
		bool			addFarray(const char* name, const int n_values = 0, const float init_value = 0, const char* help = "");
		bool			addDarray(const char* name, const int n_values = 0, const double init_value = 0, const char* help = "");

		///////////////////////////////////////////////////////////
		/// Parameters management functions - changing their values

		/// returns \c false if the name is wrong or the option has a different type
		bool			setI(const char* name, const int new_value);
		bool			setF(const char* name, const float new_value);
		bool			setD(const char* name, const double new_value);
		bool			setIarray(const char* name, int n_values);
		bool			setFarray(const char* name, int n_values);
		bool			setDarray(const char* name, int n_values);

		///////////////////////////////////////////////////////////
		/// Parameters management functions - retrieving values

		/// it the name is wrong of the option has a different type, the return value is invalid
		///	check the \c ok value
		int	getI(const char* name, bool* ok = 0);
		float	getF(const char* name, bool* ok = 0);
		double	getD(const char* name, bool* ok = 0);
		int*	getIarray(const char* name, bool* ok = 0);
		float*	getFarray(const char* name, bool* ok = 0);
		double*	getDarray(const char* name, bool* ok = 0);

		void print(const char *name = NULL);

		VariableCollector *getVariables() { return m_parameters; };

		bool copy(Parameters *parameters_);

		/// Loading/Saving the content from files
		bool		loadFile(File& file);
		bool		saveFile(File& file) const;

	protected:

		/// called when some option was changed
		virtual void	parameterChanged(const char* name) { }

	private:

		///////////////////////////////////////////////////////////
		/// Attributes

		VariableCollector*	m_parameters;
	};
}

#endif
