/**
 * @file    feature_phrase_type_and_num_words.h
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
 * The interface for a class used to check for a match with a phrase's number
 * of words
 */

#ifndef H2SL_FEATURE_PHRASE_TYPE_AND_NUM_WORDS_H
#define H2SL_FEATURE_PHRASE_TYPE_AND_NUM_WORDS_H

#include <iostream>

#include "h2sl/phrase.h"
#include "h2sl/feature.h"

namespace h2sl {
  class Feature_Phrase_Type_And_Num_Words: public Feature {
  public:
    Feature_Phrase_Type_And_Num_Words( const bool& invert = false, const unsigned int& numWords = 0, const phrase_type_t& phraseType = PHRASE_UNKNOWN );
    virtual ~Feature_Phrase_Type_And_Num_Words();
    Feature_Phrase_Type_And_Num_Words( const Feature_Phrase_Type_And_Num_Words& other );
    Feature_Phrase_Type_And_Num_Words& operator=( const Feature_Phrase_Type_And_Num_Words& other );

    virtual bool value( const unsigned int& cv, const Grounding* grounding, const std::vector< std::pair< const Phrase*, std::vector< Grounding* > > >& children, const Phrase* phrase, const World* world );
    virtual bool value( const unsigned int& cv, const Grounding* grounding, const std::vector< std::pair< const Phrase*, std::vector< Grounding* > > >& children, const Phrase* phrase, const World* world, const Grounding* context );


    virtual void to_xml( xmlDocPtr doc, xmlNodePtr root )const;

    virtual void from_xml( xmlNodePtr root );

    inline unsigned int& num_words( void ){ return _num_words; };
    inline const unsigned int& num_words( void )const{ return _num_words; };
    inline phrase_type_t& phrase_type( void ){ return _phrase_type; };
    inline const phrase_type_t& phrase_type( void )const{ return _phrase_type; };

    virtual inline const feature_type_t type( void )const{ return FEATURE_TYPE_LANGUAGE; };

  protected:
    unsigned int _num_words;
    phrase_type_t _phrase_type;

  private:

  };
  std::ostream& operator<<( std::ostream& out, const Feature_Phrase_Type_And_Num_Words& other );
}

#endif /* H2SL_FEATURE_PHRASE_TYPE_AND_NUM_WORDS_H */
