// *****************************************************************************
/*
 * Copyright (C) 2006 Olivier Tilloy <olivier@tilloy.net>
 *
 * This file is part of the pyexiv2 distribution.
 *
 * pyexiv2 is free software; you can redistribute it and/or
 * modify it under the terms of the GNU General Public License
 * as published by the Free Software Foundation; either version 2
 * of the License, or (at your option) any later version.
 *
 * pyexiv2 is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with pyexiv2; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, 5th Floor, Boston, MA 02110-1301 USA.
 */
/*
  File:      libpyexiv2_wrapper.cpp
  Author(s): Olivier Tilloy <olivier@tilloy.net>
 */
// *****************************************************************************

#include "libpyexiv2.hpp"

#include <boost/python.hpp>

using namespace boost::python;

using namespace LibPyExiv2;

BOOST_PYTHON_MODULE(libpyexiv2)
{
	register_exception_translator<Exiv2::Error>(&translateExiv2Error);

	// Exported method names prefixed by "_Image__" are going to be "private"
	// and are not meant to be used directly
	class_<Image>("Image", init<std::string>())
		.def("readMetadata", &Image::readMetadata)
		.def("writeMetadata", &Image::writeMetadata)
		.def("exifKeys", &Image::getAvailableExifTags)
		.def("isExifTagSet", &Image::isExifTagSet)
		.def("_Image__getExifTag", &Image::getExifTag)
		.def("_Image__getExifTagToString", &Image::getExifTagToString)
		.def("_Image__setExifTag", &Image::setExifTag)
		.def("_Image__deleteExifTag", &Image::deleteExifTag)
		.def("iptcKeys", &Image::getAvailableIptcTags)
		.def("isIptcTagSet", &Image::isIptcTagSet)
		.def("_Image__getIptcTag", &Image::getIptcTag)
		.def("_Image__setIptcTag", &Image::setIptcTag)
		.def("_Image__deleteIptcTag", &Image::deleteIptcTag)
		.def("getThumbnailData", &Image::getThumbnailData)
		.def("setThumbnailData", &Image::setThumbnailData)
		.def("deleteThumbnail", &Image::deleteThumbnail)
		.def("dumpThumbnailToFile", &Image::dumpThumbnailToFile)
		.def("setThumbnailFromJpegFile", &Image::setThumbnailFromJpegFile)
	;
}
