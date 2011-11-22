/**
 * @file cxx/trainer/trainer/ML_GMMTrainer.h
 * @date Tue May 10 11:35:58 2011 +0200
 * @author Francois Moulin <Francois.Moulin@idiap.ch>
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
/// @file ML_GMMTrainer.h
/// @author <a href="mailto:Roy.Wallace@idiap.ch">Roy Wallace</a> 
/// @author <a href="mailto:Laurent.El-Shafey@idiap.ch">Laurent El Shafey</a> 
/// @brief This class implements the maximum likelihood M-step of the expectation-maximisation algorithm for a GMM Machine.
/// @details See Section 9.2.2 of Bishop, "Pattern recognition and machine learning", 2006

#ifndef _ML_GMMTRAINER_H
#define _ML_GMMTRAINER_H

#include "GMMTrainer.h"
#include <limits>

namespace Torch {
namespace trainer {
/// @brief This class implements the maximum likelihood M-step of the expectation-maximisation algorithm for a GMM Machine.
/// @details See Section 9.2.2 of Bishop, "Pattern recognition and machine learning", 2006
class ML_GMMTrainer : public GMMTrainer {
  public:

    /// Default constructor
    ML_GMMTrainer(bool update_means = true, bool update_variances = false, bool update_weights = false,
      double mean_var_update_responsibilities_threshold = std::numeric_limits<double>::epsilon());

    /// Destructor
    virtual ~ML_GMMTrainer();

    /// Performs a maximum likelihood (ML) update of the GMM parameters
    /// using the accumulated statistics in m_ss
    /// Implements EMTrainer::mStep()
    void mStep (Torch::machine::GMMMachine& gmm, const Torch::io::Arrayset& data);
  
  private:

    /// Add cache to avoid re-allocation at each iteration
    mutable blitz::Array<double,1> m_cache_weights;
    mutable blitz::Array<double,1> m_cache_ss_n_thresholded;
    mutable blitz::Array<double,2> m_cache_means;
    mutable blitz::Array<double,2> m_cache_variances;
};

}}

#endif
