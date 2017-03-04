/**
 * @file number.cc
 *
 * @brief
 *
 * a class used to describe a spatial relationship
 */

#include <assert.h>

#include "h2sl/number.h"

using namespace std;
using namespace h2sl;

/**
 * Number class constructor
 */
Number::
Number( const int& value ) : Grounding(){
  insert_prop< int >( _int_properties, "value", value );
}

Number::
Number( xmlNodePtr root ) : Grounding() {
  insert_prop< int >( _int_properties, "value", 0 );
  from_xml( root );
}

/**
 * Number class copy constructor
 */
Number::
Number( const Number& other ) : Grounding( other ){

}

/**
 * Number class destructor
 */
Number::
~Number() {

}

/** 
 * Number class assignment operator
 */
Number&
Number::
operator=( const Number& other ){
  _string_properties = other._string_properties;
  _int_properties = other._int_properties;
  return (*this);
}

/** 
 * Number class equality operator
 */
bool
Number::
operator==( const Number& other )const{
  if ( value() != other.value() ){
    return false;
  } else {
    return true;
  }
}

/** 
 * Number class inequality operator
 */
bool
Number::
operator!=( const Number& other )const{
  return !( *this == other );
}

/** 
 * Number class dup operator
 */
Number*
Number::
dup( void )const{
  return new Number( *this );
}

void
Number::
scrape_grounding( const World * world,
                  vector< string >& classNames,
                  map< string, vector< string > >& stringTypes,
                  map< string, vector< int > >& intTypes )const{
  insert_unique< std::string >( class_name(), classNames );
  insert_unique< int >( "number", value(), intTypes );
  return;
}

void
Number::
fill_search_space( const Symbol_Dictionary& symbolDictionary,
                    const World* world,
                    map< string, pair< unsigned int, vector< Grounding* > > >& searchSpaces,
                    const symbol_type_t& symbolType ){

  if( symbolDictionary.has_class_name( class_name() ) ){
    map< string, pair< unsigned int, vector< Grounding* > > >::iterator it_search_spaces_symbol = searchSpaces.find( class_name() );
    if( it_search_spaces_symbol == searchSpaces.end() ){
      searchSpaces.insert( pair< string, pair< unsigned int, vector< Grounding* > > >( class_name(), pair< unsigned int, vector< Grounding* > >( 0, vector< Grounding* >() ) ) );
      it_search_spaces_symbol = searchSpaces.find( class_name() );
    }  

    map< string, vector< int > >::const_iterator it_number_value_types = symbolDictionary.int_types().find( "number" );

    switch( symbolType ){
    case( SYMBOL_TYPE_CONCRETE ):
    case( SYMBOL_TYPE_ALL ):
      if( it_number_value_types != symbolDictionary.int_types().end() ){
        for( unsigned int i = 0; i < it_number_value_types->second.size(); i++ ){
          it_search_spaces_symbol->second.second.push_back( new Number( it_number_value_types->second[ i ] ) );
        }
      }
      break;
    case( SYMBOL_TYPE_ABSTRACT ):
    case( NUM_SYMBOL_TYPES ):
    default:
      break;
    }
  }

  return;
}

/** 
 * imports the Number class from an XML file
 */
void
Number::
from_xml( const string& filename ){
  xmlDoc * doc = NULL;
  xmlNodePtr root = NULL;
  doc = xmlReadFile( filename.c_str(), NULL, 0 );
  if( doc != NULL ){
    root = xmlDocGetRootElement( doc );
    if( root->type == XML_ELEMENT_NODE ){
      xmlNodePtr l1 = NULL;
      for( l1 = root->children; l1; l1 = l1->next ){
        if( l1->type == XML_ELEMENT_NODE ){
          if( xmlStrcmp( l1->name, ( const xmlChar* )( "number" ) ) == 0 ){
            from_xml( l1 );
          }
        }
      }
      xmlFreeDoc( doc );
    } else {
      xmlFreeDoc( doc );
    }
  }
  return;
}

/** 
 * imports the Number class from an XML node pointer
 */
void
Number::
from_xml( xmlNodePtr root ){
  value() = 0;
  if( root->type == XML_ELEMENT_NODE ){
    vector< string > number_keys = { "value", "type" };
    assert( check_keys( root, number_keys ) );
    pair< bool, int > value_prop = has_prop< int >( root, "value" );
    if( value_prop.first ){
      value() = value_prop.second;
    }
    value_prop = has_prop< int >( root, "type" );
    if( value_prop.first ){
      value() = value_prop.second;
    }
  }
  return;
}

/**
 * exports the Number class to an XML file
 */
void
Number::
to_xml( const string& filename )const{
  xmlDocPtr doc = xmlNewDoc( ( xmlChar* )( "1.0" ) );
  xmlNodePtr root = xmlNewDocNode( doc, NULL, ( xmlChar* )( "root" ), NULL );
  xmlDocSetRootElement( doc, root );
  to_xml( doc, root );
  xmlSaveFormatFileEnc( filename.c_str(), doc, "UTF-8", 1 );
  xmlFreeDoc( doc );
  return;
}

/**
 * exports the Number class to an XML node pointer
 */
void
Number::
to_xml( xmlDocPtr doc,
        xmlNodePtr root )const{
  xmlNodePtr node = xmlNewDocNode( doc, NULL, ( xmlChar* )( "number" ), NULL );
  xmlNewProp( node, ( const xmlChar* )( "value" ), ( const xmlChar* )( to_std_string( get_prop< int >( _int_properties, "value" ) ).c_str()  ) );
  xmlAddChild( root, node );
  return;
}

namespace h2sl {
  /** 
   * Number class ostream operator
   */
  ostream&
  operator<<( ostream& out,
              const Number& other ){
    out << "Number(";
    out << "value=\"" << other.value() << "\"";
    out << ")";
    return out;
  }
}
