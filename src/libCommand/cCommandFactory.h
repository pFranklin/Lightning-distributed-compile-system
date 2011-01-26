#ifndef cCommandFactory_h
#define cCommandFactory_h

#include <string>
#include <map>
#include <boost/function.hpp>

/** cCommandFactory
 * iCommand interface factory.
 *
 * This class is responsible for creating the command product
 * for generating compiler command line.
 */

class iCommand;

typedef boost::function<iCommand*() > iCommandFactory;

class cCommandFactory {
public:
    /** Constructor to generate factory table */
    cCommandFactory();

    /** Virtual destructor to cleanup subclasses properly.  */
    virtual ~cCommandFactory();

    /** Product creator, productName must be UTF-8 string
     *  if succeed, return a pointer of iDepends, or it
     *  will return 0*/
    iCommand *CreateCommandProduct(std::string productName);

protected:
    /** Init the products that factory can create */
    void InitProducts();

protected:
    /** Products map */
    std::map<std::string, iCommandFactory> m_factories;
};

#endif
