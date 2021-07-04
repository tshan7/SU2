/*!
 * \file CRectangularMeshReaderFEM.hpp
 * \brief Header file for the class CRectangularMeshReaderFEM.
 *        The implementations are in the <i>CRectangularMeshReaderFEM.cpp</i> file.
 * \author T. Economon, E. van der Weide
 * \version 7.1.1 "Blackbird"
 *
 * SU2 Project Website: https://su2code.github.io
 *
 * The SU2 Project is maintained by the SU2 Foundation 
 * (http://su2foundation.org)
 *
 * Copyright 2012-2020, SU2 Contributors (cf. AUTHORS.md)
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

#include "CMeshReader.hpp"

/*!
 * \class CRectangularMeshReaderFEM
 * \brief Reads a 2D rectangular grid into linear partitions for the finite element solver (FEM).
 * \author: T. Economon, E. van der Weide
 */
class CRectangularMeshReaderFEM final: public CMeshReader {
  
private:
  
  unsigned long nNode; /*!< \brief Number of grid nodes in the x-direction. */
  unsigned long mNode; /*!< \brief Number of grid nodes in the y-direction. */
  
  su2double Lx; /*!< \brief Length of the domain in the x-direction. */
  su2double Ly; /*!< \brief Length of the domain in the y-direction. */
  
  su2double Ox; /*!< \brief Offset of the domain from 0.0 in the x-direction. */
  su2double Oy; /*!< \brief Offset of the domain from 0.0 in the y-direction. */
  
  unsigned short KindElem;  /*!< \brief VTK identifier of the interior elements. */
  unsigned short KindBound; /*!< \brief VTK identifier of the surface elements. */

  unsigned short nPolySol; /*!< \brief Polynomial degree of the solution. */
  
  /*!
   * \brief Computes and stores the grid points based on an analytic definition of a rectangular grid.
   */
  void ComputeRectangularPointCoordinates();
  
  /*!
   * \brief Computes and stores the volume element connectivity based on an analytic definition of a rectangular grid.
   */
  void ComputeRectangularVolumeConnectivity();
  
  /*!
   * \brief Computes and stores the surface element connectivity based on an analytic definition of a rectangular grid.
   */
  void ComputeRectangularSurfaceConnectivity();
  
public:
  
  /*!
   * \brief Constructor of the CRectangularMeshReaderFEM class.
   */
  CRectangularMeshReaderFEM(CConfig        *val_config,
                            unsigned short val_iZone,
                            unsigned short val_nZone);
  
  /*!
   * \brief Destructor of the CRectangularMeshReaderFEM class.
   */
  ~CRectangularMeshReaderFEM(void);
  
};