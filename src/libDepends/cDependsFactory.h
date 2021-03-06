/*============================================================================
  Lightning - Cross Platform Distributed Building System
  Copyright 2010-2011 Paul Franklin

  Distributed under the GNU General Public License v2.0 License or later;
  see accompanying file license for details.

  This software is distributed WITHOUT ANY WARRANTY; without even the
  implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
  See the License for more information.
============================================================================*/


#ifndef cDependsFactory_h
#define cependsFactory_h

#include <string>
#include <map>
#include <boost/function.hpp>

/** cDependsFactory
 * iDepends interface factory.
 *
 * This class is responsible for creating the depends product
 * for generating source file dependency.
 */

class iDepends;

typedef boost::function<iDepends*() > iDependsFactory;

class cDependsFactory {
public:
    /** Constructor to generate factory table */
    cDependsFactory();

    /** Virtual destructor to cleanup subclasses properly.  */
    virtual ~cDependsFactory();

    /** Product creator, productName must be UTF-8 string
     *  if succeed, return a pointer of iDepends, or it
     *  will return 0*/
    iDepends *CreateDependsProduct(std::string productName);

protected:
    /** Init the products that factory can create */
    void InitProducts();

protected:
    /** Products map */
    std::map<std::string, iDependsFactory> m_factories;
};

#endif
