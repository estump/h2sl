/**
 * @file    feature_grounding_string_property_value_matches_child_string_property_value.h
 * @author  Thomas M. Howard (tmhoward@csail.mit.edu)
 *          Matthew R. Walter (mwalter@csail.mit.edu)
 * @version 1.0
 *
 * @section LICENSE
 *
 * This file is part of h2sl.
 *
 * Copyright (C) 2014 by the Massachusetts Institute of Technology
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or (at
 * your option) any later version.
 * 
 * This program is distributed in the hope that it will be useful, but
 * WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * General Public License for more details.
 * 
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, see
 * <http://www.gnu.org/licenses/gpl-2.0.html> or write to the Free
 * Software Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA
 * 02110-1301, USA.
 *
 * @section DESCRIPTION
 *
 * The interface for a class to check a grounding's property
 */

#ifndef H2SL_FEATURE_GROUNDING_STRING_PROPERTY_VALUE_MATCHES_CHILD_STRING_PROPERTY_VALUE_H
#define H2SL_FEATURE_GROUNDING_STRING_PROPERTY_VALUE_MATCHES_CHILD_STRING_PROPERTY_VALUE_H

#include <iostream>

#include <h2sl/feature.h>

namespace h2sl {
  class Feature_Grounding_String_Property_Value_Matches_Child_String_Property_Value: public Feature {
  public:
    Feature_Grounding_String_Property_Value_Matches_Child_String_Property_Value( const bool& invert = false, const std::string& classNameGrounding = "na", const std::string& propertyKeyGrounding = "na", const std::string& classNameChild = "na", const std::string& propertyKeyChild = "na" );
    Feature_Grounding_String_Property_Value_Matches_Child_String_Property_Value( xmlNodePtr root );
    virtual ~Feature_Grounding_String_Property_Value_Matches_Child_String_Property_Value();
    Feature_Grounding_String_Property_Value_Matches_Child_String_Property_Value( const Feature_Grounding_String_Property_Value_Matches_Child_String_Property_Value& other );
    Feature_Grounding_String_Property_Value_Matches_Child_String_Property_Value& operator=( const Feature_Grounding_String_Property_Value_Matches_Child_String_Property_Value& other );

    virtual bool value( const unsigned int& cv, const Grounding* grounding, const std::vector< std::pair< const Phrase*, std::vector< Grounding* > > >& children, const Phrase* phrase, const World* world );
    virtual bool value( const unsigned int& cv, const Grounding* grounding, const std::vector< std::pair< const Phrase*, std::vector< Grounding* > > >& children, const Phrase* phrase, const World* world, const Grounding* context );


    virtual void to_xml( xmlDocPtr doc, xmlNodePtr root )const;

    virtual void from_xml( xmlNodePtr root );

    std::string& class_name_grounding( void );
    const std::string& class_name_grounding( void )const;
    std::string& key_grounding( void );
    const std::string& key_grounding( void )const;
    std::string& class_name_child( void );
    const std::string& class_name_child( void )const;
    std::string& key_child( void );
    const std::string& key_child( void )const;

    virtual inline const feature_type_t type( void )const{ return FEATURE_TYPE_GROUNDING; };

  protected:
    std::string _class_name_grounding;
    std::string _key_grounding;
    std::string _class_name_child;
    std::string _key_child;

  private:

  };
  std::ostream& operator<<( std::ostream& out, const Feature_Grounding_String_Property_Value_Matches_Child_String_Property_Value& other );
}

#endif /* H2SL_FEATURE_GROUNDING_STRING_PROPERTY_VALUE_MATCHES_CHILD_STRING_PROPERTY_VALUE_H */