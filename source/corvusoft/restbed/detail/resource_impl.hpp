/*
 * Copyright (c) 2013, 2014, 2015 Corvusoft
 */

#ifndef _RESTBED_DETAIL_RESOURCE_IMPL_H
#define _RESTBED_DETAIL_RESOURCE_IMPL_H 1

//System Includes
#include <map>
#include <set>
#include <string>
#include <vector>
#include <functional>

//Project Includes

//External Includes

//System Namespaces

//Project Namespaces

//External Namespaces

namespace restbed
{
    //Forward Declarations
    class Rule;
    class Session;
    
    namespace detail
    {
        //Forward Declarations
        
        struct ResourceImpl
        {
            std::set< std::string > paths { };
            
            std::set< std::string > methods { };
            
            std::vector< std::shared_ptr< Rule > > rules { };
            
            std::multimap< std::string, std::string > default_headers { };
            
            std::function< void ( const std::shared_ptr< Session > ) > failed_filter_validation_handler = nullptr;
            
            std::function< void ( const int, const std::exception&, const std::shared_ptr< Session > ) > error_handler = nullptr;
            
            std::function< void ( const std::shared_ptr< Session >, const std::function< void ( const std::shared_ptr< Session > ) >& ) > authentication_handler = nullptr;
            
            std::multimap< std::string, std::pair< std::multimap< std::string, std::string >, std::function< void ( const std::shared_ptr< Session > ) > > > method_handlers { };
        };
    }
}

#endif  /* _RESTBED_DETAIL_RESOURCE_IMPL_H */
