/*################################################################################
  ##
  ##   Copyright (C) 2011-2023 Keith O'Hara
  ##
  ##   This file is part of the StatsLib C++ library.
  ##
  ##   Licensed under the Apache License, Version 2.0 (the "License");
  ##   you may not use this file except in compliance with the License.
  ##   You may obtain a copy of the License at
  ##
  ##       http://www.apache.org/licenses/LICENSE-2.0
  ##
  ##   Unless required by applicable law or agreed to in writing, software
  ##   distributed under the License is distributed on an "AS IS" BASIS,
  ##   WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
  ##   See the License for the specific language governing permissions and
  ##   limitations under the License.
  ##
  ################################################################################*/

/* 
 * Sample from a logistic distribution
 */

#ifndef _statslib_rlogis_HPP
#define _statslib_rlogis_HPP

//
// scalar output

/**
 * Random sampling function for the Logistic distribution
 *
 * @param mu_par the location parameter, a real-valued input.
 * @param sigma_par the scale parameter, a real-valued input.
 * @param engine a random engine, passed by reference.
 *
 * @return a pseudo-random draw from the Logistic distribution.
 *
 * Example:
 * \code{.cpp}
 * stats::rand_engine_t engine(1776);
 * stats::rlogis(1.0,2.0,engine);
 * \endcode
 */

template<typename T1, typename T2>
statslib_inline
common_return_t<T1,T2>
rlogis(const T1 mu_par, const T2 sigma_par, rand_engine_t& engine);

/**
 * Random sampling function for the Logistic distribution
 *
 * @param mu_par the location parameter, a real-valued input.
 * @param sigma_par the scale parameter, a real-valued input.
 * @param seed_val initialize the random engine with a non-negative integral-valued seed.
 *
 * @return a pseudo-random draw from the Logistic distribution.
 *
 * Example:
 * \code{.cpp}
 * stats::rlogis(1.0,2.0,1776);
 * \endcode
 */

template<typename T1, typename T2>
statslib_inline
common_return_t<T1,T2>
rlogis(const T1 mu_par, const T2 sigma_par, const ullint_t seed_val = std::random_device{}());

//
// vector/matrix output

#ifdef STATS_ENABLE_MATRIX_FEATURES

/**
 * @brief Random matrix sampling function for the Logistic distribution
 *
 * @param n the number of output rows
 * @param k the number of output columns
 * @param mu_par the location parameter, a real-valued input.
 * @param sigma_par the scale parameter, a real-valued input.
 * @param engine a random engine, passed by reference.
 *
 * @return a matrix of pseudo-random draws from the Logistic distribution.
 *
 * Example:
 * \code{.cpp}
 * stats::rand_engine_t engine(1776);
 * // std::vector
 * stats::rlogis<std::vector<double>>(5,4,1.0,2.0,engine);
 * // Armadillo matrix
 * stats::rlogis<arma::mat>(5,4,1.0,2.0,engine);
 * // Blaze dynamic matrix
 * stats::rlogis<blaze::DynamicMatrix<double,blaze::columnMajor>>(5,4,1.0,2.0,engine);
 * // Eigen dynamic matrix
 * stats::rlogis<Eigen::MatrixXd>(5,4,1.0,2.0,engine);
 * \endcode
 *
 * @note This function requires template instantiation; acceptable output types include: <tt>std::vector</tt>, with element type \c float, \c double, etc., as well as Armadillo, Blaze, and Eigen dense matrices.
 */

template<typename mT, typename T1, typename T2>
statslib_inline
mT
rlogis(const ullint_t n, const ullint_t k, const T1 mu_par, const T2 sigma_par, rand_engine_t& engine);

/**
 * @brief Random matrix sampling function for the Logistic distribution
 *
 * @param n the number of output rows
 * @param k the number of output columns
 * @param mu_par the location parameter, a real-valued input.
 * @param sigma_par the scale parameter, a real-valued input.
 * @param seed_val initialize the random engine with a non-negative integral-valued seed.
 *
 * @return a matrix of pseudo-random draws from the Logistic distribution.
 *
 * Example:
 * \code{.cpp}
 * // std::vector
 * stats::rlogis<std::vector<double>>(5,4,1.0,2.0);
 * // Armadillo matrix
 * stats::rlogis<arma::mat>(5,4,1.0,2.0);
 * // Blaze dynamic matrix
 * stats::rlogis<blaze::DynamicMatrix<double,blaze::columnMajor>>(5,4,1.0,2.0);
 * // Eigen dynamic matrix
 * stats::rlogis<Eigen::MatrixXd>(5,4,1.0,2.0);
 * \endcode
 *
 * @note This function requires template instantiation; acceptable output types include: <tt>std::vector</tt>, with element type \c float, \c double, etc., as well as Armadillo, Blaze, and Eigen dense matrices.
 */

template<typename mT, typename T1, typename T2>
statslib_inline
mT
rlogis(const ullint_t n, const ullint_t k, const T1 mu_par, const T2 sigma_par, const ullint_t seed_val = std::random_device{}());

#endif

//
// include implementation files

#include "rlogis.ipp"

#endif
