#ifndef CTLIB_WEIGHT_DATA_H
#define CTLIB_WEIGHT_DATA_H
/*******************************************************************************
* -Academic Honesty-
* Plagarism: The unauthorized use or close imitation of the language and 
* thoughts of another author and the representation of them as one's own 
* original work, as by not crediting the author. 
* (Encyclopedia Britannica, 2008.)
*
* You are free to use the code according to the license below, but, please
* do not commit acts of academic dishonesty. We strongly encourage and request 
* that for any [academic] use of this source code one should cite one the 
* following works:
* 
* \cite{hatcher, z-ct-10}
* 
* See ct.bib for the corresponding bibtex entries. 
* !!! DO NOT CITE THE USER MANUAL !!!
*******************************************************************************
* Copyright (C) Ryan H. Lewis 2014 <me@ryanlewis.net>
*******************************************************************************
*******************************************************************************
* NOTES
*
*
*******************************************************************************/

//non-exported functionality
namespace ctl {
namespace detail{} // end namespace detail
} //ctl namespace

//exported functionality
namespace ctl{

template< typename Weight_, typename Weight_less_ = std::less< Weight_> >
class Weight_data {
public:
  typedef Weight_ Weight;
  typedef Weight_less_ Weight_less;

  Weight_data( const Weight& weight = Weight( 0)) : weight_( weight) {}
  Weight_data( const Weight_data &from) : weight_( from.weight_) {}
  Weight_data( Weight_data &&from) : weight_( std::move( from.weight_)) {}

  // assignment operator
  Weight_data& operator=( const Weight_data& from) {
    weight_ = from.weight_;
    return *this;
  }
  // assignment operator
  Weight_data& operator=( Weight_data&& from) {
    weight_ = std::move( from.weight_);
    return *this;
  }
  
  Weight&        weight()         { return weight_; }
  void 		 weight( const Weight & w)         { weight_ = w; }
  const Weight   weight() const   { return weight_; }
private:
  Weight_ weight_;
}; // class Weight_data

struct Weight_less {
  template< typename Cell_iterator>
  bool operator()( const Cell_iterator& a, const Cell_iterator& b) const {
    if( a->second.weight() < b->second.weight()) return true;
    if( b->second.weight() > a->second.weight()) return false;
    return a->first < b->first;
  }
}; // struct Weight_less

} //namespace ctl


#endif //CTLIB_WEIGHT_DATA_H
