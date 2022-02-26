#include "stlexam.h"
#pragma hdrstop
/**************************************************************************
 *
 * partsum.cpp - Example program for partial sum. See Class Reference Section
 *
 ***************************************************************************
 *
 * (c) Copyright 1994, 1998 Rogue Wave Software, Inc.
 * ALL RIGHTS RESERVED
 *
 * The software and information contained herein are proprietary to, and
 * comprise valuable trade secrets of, Rogue Wave Software, Inc., which
 * intends to preserve as trade secrets such software and information.
 * This software is furnished pursuant to a written license agreement and
 * may be used, copied, transmitted, and stored only in accordance with
 * the terms of such license and with the inclusion of the above copyright
 * notice.  This software and information or any other copies thereof may
 * not be provided or otherwise made available to any other person.
 *
 * Notwithstanding any other lease or license that may pertain to, or
 * accompany the delivery of, this computer software and information, the
 * rights of the Government regarding its use, reproduction and disclosure
 * are as set forth in Section 52.227-19 of the FARS Computer
 * Software-Restricted Rights clause.
 *
 * Use, duplication, or disclosure by the Government is subject to
 * restrictions as set forth in subparagraph (c)(1)(ii) of the Rights in
 * Technical Data and Computer Software clause at DFARS 252.227-7013.
 * Contractor/Manufacturer is Rogue Wave Software, Inc.,
 * P.O. Box 2328, Corvallis, Oregon 97339.
 *
 * This computer software and information is distributed with "restricted
 * rights."  Use, duplication or disclosure is subject to restrictions as
 * set forth in NASA FAR SUP 18-52.227-79 (April 1985) "Commercial
 * Computer Software-Restricted Rights (April 1985)."  If the Clause at
 * 18-52.227-74 "Rights in Data General" is specified in the contract,
 * then the "Alternate III" clause applies.
 *
 **************************************************************************/

#include <numeric>    // For accumulate.
#include <vector>     // For vector.
#include <functional> // For multiplies.
 
#ifdef _RW_STD_IOSTREAM
#include <iostream>
#else
#include <iostream.h>
#endif     

int main ()
{
#ifndef _RWSTD_NO_NAMESPACE
  using namespace std;
#endif

  //
  // Initialize a vector using an array of integers.
  //
  int d1[10] = {1,2,3,4,5,6,7,8,9,10};
  vector<int,allocator<int> > v(d1+0, d1+10);
  //
  // Create an empty vectors to store results.
  //
  vector<int,allocator<int> > sums((size_t)10), prods((size_t)10);
  //
  // Compute partial_sums and partial_products.
  //
  partial_sum(v.begin(), v.end(), sums.begin());
  partial_sum(v.begin(), v.end(), prods.begin(), multiplies<int>());
  //
  // Output the results.
  //
  cout << "For the series: " << endl << "     ";
  copy(v.begin(),v.end(),ostream_iterator<int,char,char_traits<char> >(cout," "));
  cout << endl << endl;

  cout << "The partial sums: " << endl << "     " ;
  copy(sums.begin(),sums.end(), ostream_iterator<int,char,char_traits<char> >(cout," "));
  cout <<" should each equal (N*N + N)/2" << endl << endl;

  cout << "The partial products: " << endl << "     ";
  copy(prods.begin(),prods.end(), ostream_iterator<int,char,char_traits<char> >(cout," "));
  cout << " should each equal N!" << endl;

  return 0;
}


