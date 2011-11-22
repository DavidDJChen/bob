/**
 * @file cxx/old/scanning/src/ExhaustiveScaleExplorer.cc
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
#include "scanning/ExhaustiveScaleExplorer.h"
#include "scanning/ipSWEvaluator.h"

namespace Torch
{

/////////////////////////////////////////////////////////////////////////
// Constructor

ExhaustiveScaleExplorer::ExhaustiveScaleExplorer()
	: 	ScaleExplorer()
{
	addFOption("dx", 0.1f, "OX variation of the scanning sub-window width");
	addFOption("dy", 0.1f, "OY variation of the scanning sub-window height");
}

/////////////////////////////////////////////////////////////////////////
// Destructor

ExhaustiveScaleExplorer::~ExhaustiveScaleExplorer()
{
}

/////////////////////////////////////////////////////////////////////////
// Process the scale, searching for patterns at different sub-windows

bool ExhaustiveScaleExplorer::process(	ExplorerData& explorerData,
					bool stopAtFirstDetection)
{
        const int sw_w = m_sw_size.w;
	const int sw_h = m_sw_size.h;

	// Compute the location variance (related to the subwindow size)
	//const int model_w = explorerData.m_swEvaluator->getModelWidth();
	//const int model_h = explorerData.m_swEvaluator->getModelHeight();

	const int dx = getInRange(FixI(getFOption("dx") * sw_w), 1, sw_w);
	const int dy = getInRange(FixI(getFOption("dy") * sw_h), 1, sw_h);

	const bool verbose = getBOption("verbose");

	///////////////////////////////////////////////////////////////////////
	// Generate all possible sub-windows to scan

	// ... compute the range in which the position can vary
	const int sw_min_x = m_roi.x;
	const int sw_max_x = m_roi.x + m_roi.w - sw_w;
	const int sw_min_y = m_roi.y;
	const int sw_max_y = m_roi.y + m_roi.h - sw_h;

	// ... and vary the position
	int count = 0;
	for (int sw_x = sw_min_x; sw_x < sw_max_x; sw_x += dx)
		for (int sw_y = sw_min_y; sw_y < sw_max_y; sw_y += dy)
		{
		        if (ScaleExplorer::processSW(sw_x, sw_y, sw_w, sw_h, explorerData) == true)
			{
				// Stop at the first detection if asked
				if (stopAtFirstDetection && explorerData.m_patterns.isEmpty() == false)
				{
					// This will exit gracefully the double <for>
					sw_x = sw_max_x + 1;
					sw_y = sw_max_y + 1;
				}

				count ++;
			}
		}

	// ... debug message
	if (verbose == true)
	{
		Torch::print("\t[ExhaustiveScaleExplorer]: [%d] SWs [%dx%d]: pruned = %d, scanned = %d, accepted = %d\n",
				count, sw_w, sw_h,
				explorerData.m_stat_prunned,
				explorerData.m_stat_scanned,
				explorerData.m_stat_accepted);
	}

	// OK
	return true;
}

/////////////////////////////////////////////////////////////////////////

}
