/*!
 * \file CFileReaderLUT.hpp
 * \brief reading lookup table for tabulated fluid properties
 * \author D. Mayer, T. Economon
 * \version 7.4.0 "Blackbird"
 *
 * SU2 Project Website: https://su2code.github.io
 *
 * The SU2 Project is maintained by the SU2 Foundation
 * (http://su2foundation.org)
 *
 * Copyright 2012-2022, SU2 Contributors (cf. AUTHORS.md)
 *
 * SU2 is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Lesser General Public
 * License as published by the Free Software Foundation; either
 * version 2.1 of the License, or (at your option) any later version.
 *
 * SU2 is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU
 * Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public
 * License along with SU2. If not, see <http://www.gnu.org/licenses/>.
 */
#pragma once

#include <fstream>
#include <string>
#include <vector>

#include "../../Common/include/parallelization/mpi_structure.hpp"
#include "../../../Common/include/linear_algebra/blas_structure.hpp"
#include "../../../Common/include/toolboxes/CSquareMatrixCM.hpp"

class CFileReaderLUT {
 protected:
  int rank;

  std::string version_lut;
  std::string version_reader;
  unsigned long n_points;
  unsigned long n_triangles;
  unsigned long n_hull_points;
  unsigned long n_variables;

  /*! \brief Holds the variable names stored in the table file. 
   * Order is in sync with tableFlamelet.
   */
  std::vector<std::string> names_var;

  /*! \brief Holds all data stored in the table. 
   * First index addresses the variable while second index addresses the point.
   */
  su2activematrix table_data;

  su2matrix<unsigned long> triangles;

  std::vector<unsigned long> hull;

  std::string SkipToFlag(std::ifstream* file_stream, const std::string& flag);

 public:
  CFileReaderLUT(){};
  
  inline const std::string& GetVersionLUT() const { return version_lut; }
  inline const std::string& GetVersionReader() const { return version_reader; }
  inline unsigned long GetNPoints() const { return n_points; }
  inline unsigned long GetNTriangles() const { return n_triangles; }
  inline unsigned long GetNHullPoints() const { return n_hull_points; }
  inline unsigned long GetNVariables() const { return n_variables; }

  inline const std::vector<std::string>& GetNamesVar() const { return names_var; }

  inline const su2activematrix& GetTableData() const { return table_data; }

  inline const su2matrix<unsigned long>& GetTriangles() const { return triangles; };

  inline const std::vector<unsigned long>& GetHull() const { return hull; };

  void ReadRawDRG(const std::string& file_name);
};
