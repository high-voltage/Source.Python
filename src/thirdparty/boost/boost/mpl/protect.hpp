
#ifndef BOOST_MPL_PROTECT_HPP_INCLUDED
#define BOOST_MPL_PROTECT_HPP_INCLUDED

// Copyright Peter Dimov 2001
// Copyright Aleksey Gurtovoy 2002-2004
//
// Distributed under the Boost Software License, Version 1.0. 
// (See accompanying file LICENSE_1_0.txt or copy at 
// http://www.boost.org/LICENSE_1_0.txt)
//
// See http://www.boost.org/libs/mpl for documentation.

// $Id: protect.hpp 85961 2013-09-26 14:10:37Z skelly $
// $Date: 2013-09-26 10:10:37 -0400 (Thu, 26 Sep 2013) $
// $Revision: 85961 $

#include <boost/mpl/aux_/arity.hpp>
#include <boost/mpl/aux_/config/dtp.hpp>
#include <boost/mpl/aux_/na_spec.hpp>

namespace boost { namespace mpl {

template<
      typename BOOST_MPL_AUX_NA_PARAM(T)
    , int not_le_ = 0
    >
struct protect : T
{
#if BOOST_WORKAROUND(__EDG_VERSION__, == 238)
    typedef mpl::protect type;
#else
    typedef protect type;
#endif
};

#if defined(BOOST_MPL_CFG_BROKEN_DEFAULT_PARAMETERS_IN_NESTED_TEMPLATES)
namespace aux { 
template< int N, typename T >
struct arity< protect<T>, N > 
    : arity<T,N>
{ 
};
} // namespace aux
#endif

BOOST_MPL_AUX_NA_SPEC_MAIN(1, protect)
#if !defined(BOOST_MPL_CFG_NO_FULL_LAMBDA_SUPPORT)
BOOST_MPL_AUX_NA_SPEC_TEMPLATE_ARITY(1, 1, protect)
#endif

}}

#endif // BOOST_MPL_PROTECT_HPP_INCLUDED
