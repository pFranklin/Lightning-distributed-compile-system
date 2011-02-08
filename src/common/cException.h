/*============================================================================
  Lightning - Cross Platform Distributed Building System
  Copyright 2010-2011 Paul Franklin

  Distributed under the GNU General Public License v2.0 License or later;
  see accompanying file license for details.

  This software is distributed WITHOUT ANY WARRANTY; without even the
  implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
  See the License for more information.
============================================================================*/


#ifndef cException_h
#define cException_h

#include <stdexcept>
#include <string>

/* cException
 * exception class.
 *
 * This class is responsible for handling exception
 * of the building system.
 */

class cException : public std::exception {
public:

    /** Constructor of the class. */
    cException(const char *exp) throw () {
        m_ExpString = exp;
    }

    /** Virtual destructor to cleanup subclasses properly.  */
    virtual ~cException() throw () {
    }

    /** Returns a C-style character string describing the general cause
     *  of the current error.  */
    virtual const char* what() const throw () {
        return m_ExpString.c_str();
    }

protected:
    /** exception string.  */
    std::string m_ExpString;
};

#endif

