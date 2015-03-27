#ifndef CTL_RECOMBINE_H
#define CTL_RECOMBINE_H
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
*
* This program is free software; you can redistribute it and/or
* modify it under the terms of the GNU General Public License
* as published by the Free Software Foundation; either version 2
* of the License, or (at your option) any later version.
*
* This program is distributed in the hope that it will be useful,
* but WITHOUT ANY WARRANTY; without even the implied warranty of
* MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
* GNU General Public License for more details.
*
* You should have received a copy of the GNU General Public License
* along with this program in a file entitled COPYING; if not, write to the
* Free Software Foundation, Inc.,
* 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301, USA.
*******************************************************************************
* NOTES:
* File contains some metaprogramming utilities that are used in places.
*******************************************************************************/

namespace ctl{
namespace detail{
 struct Dummy{};
/**
* Flex your meta-muscles
* Understand why
* recombine< int, int>::type is int
* recombine< int, T>::type is T
* recombine< any_type_without_angle_brackets, T> is T
* recombine< Foo< Bar>, T> is Foo< T> 
* recombine< pair< Foo, Bar, baz>, T> is T
*/
template <typename T, typename R>  
struct recombine{ using type = T; }; //recombine struct
 
template < template <typename> class TT, 
           typename T, typename R>  
struct recombine<TT<T>,R> { using type = TT<R>; }; 

} //end namespace detail 
} //end namespace ctl

#endif