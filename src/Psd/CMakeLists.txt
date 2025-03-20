# CMake build for psd_sdk
# Copyright 2023, heavenstone <heavenstone1308@gmail.com>
# See LICENSE.txt for licensing details (2-clause BSD License: https://opensource.org/licenses/BSD-2-Clause)

cmake_minimum_required(VERSION 3.16)

project(Psd)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

MESSAGE("-- PSD=>CMAKE_HOST_SYSTEM_NAME ${CMAKE_HOST_SYSTEM_NAME}")
MESSAGE("-- PSD=>CMAKE_HOST_SYSTEM_VERSION ${CMAKE_HOST_SYSTEM_VERSION}")
if(manual)
    MESSAGE("-- PSD=>Manual mode")
else()
    MESSAGE("-- PSD=>Automatic mode")
endif()

set(psd_source_exporter
  PsdExport.h
  PsdExport.cpp
  PsdExportChannel.h
  PsdExportColorMode.h
  PsdExportDocument.h
  PsdExportLayer.h
  PsdExportMetaDataAttribute.h
)

set(psd_source_image_util
  PsdDecompressRle.h
  PsdDecompressRle.cpp
  PsdInterleave.h
  PsdInterleave.cpp
  PsdLayerCanvasCopy.h
  PsdLayerCanvasCopy.cpp
)

set(psd_source_interfaces
  PsdAllocator.h
  PsdAllocator.cpp
  PsdFile.h
  PsdFile.cpp
  PsdMallocAllocator.h
  PsdMallocAllocator.cpp
)
if (WIN32)
  list(APPEND psd_source_interfaces
    PsdNativeFile.h
    PsdNativeFile.cpp
  )
  message("-- PSD=>PROJECT_PLATFORM=WINDOWS")
elseif (APPLE)
  list(APPEND psd_source_interfaces
    PsdNativeFile_Mac.h
    PsdNativeFile_Mac.mm
  )
  message("-- PSD=>PROJECT_PLATFORM=APPLE")
else()
  list(APPEND psd_source_interfaces
    PsdNativeFile_Linux.h
    PsdNativeFile_Linux.cpp
  )
  message("-- PSD=>PROJECT_PLATFORM=LINUX")
endif()


set(psd_source_parser
  PsdParseColorModeDataSection.h
  PsdParseColorModeDataSection.cpp
  PsdParseDocument.h
  PsdParseDocument.cpp
  PsdParseImageDataSection.h
  PsdParseImageDataSection.cpp
  PsdParseImageResourcesSection.h
  PsdParseImageResourcesSection.cpp
  PsdParseLayerMaskSection.h
  PsdParseLayerMaskSection.cpp
)

set(psd_source_platform
  PsdAssert.h
  PsdCompilerMacros.h
  PsdLog.h
  PsdNamespace.h
  PsdPlatform.h
  PsdTypes.h
)

set(psd_source_sections
  PsdColorModeDataSection.h
  PsdImageDataSection.h
  PsdImageResourcesSection.h
  PsdLayerMaskSection.h
)

set(psd_source_types
  PsdAlphaChannel.h
  PsdBlendMode.h
  PsdBlendMode.cpp
  PsdChannel.h
  PsdColorMode.h
  PsdColorMode.cpp
  PsdCompressionType.h
  PsdDocument.h
  PsdImageResourceType.h
  PsdLayer.h
  PsdLayerMask.h
  PsdLayerType.h
  PsdPlanarImage.h
  PsdSection.h
  PsdVectorMask.h
  PsdSheetColor.cpp
  PsdSheetColor.h
)

set(psd_source_util
  PsdBitUtil.h
  PsdBitUtil.inl
  PsdEndianConversion.h
  PsdEndianConversion.inl
  PsdFixedSizeString.h
  PsdFixedSizeString.cpp
  PsdKey.h
  PsdMemoryUtil.h
  PsdMemoryUtil.inl
  PsdSyncFileReader.h
  PsdSyncFileReader.cpp
  PsdSyncFileUtil.h
  PsdSyncFileUtil.inl
  PsdSyncFileWriter.h
  PsdSyncFileWriter.cpp
  PsdUnionCast.h
  PsdUnionCast.inl
)

set(psd_source_zip
  Psdminiz.h
  Psdminiz.c
)

set(psd_source_support

)

set(psd_source_
  Psd.h
  PsdDocumentation.h
  Psdinttypes.h
  Psdispod.h
  Psdisunsigned.h
  PsdPch.h
  PsdPch.cpp
  Psdstdint.h
)

set(psd_source
  ${psd_source_exporter}
  ${psd_source_image_util}
  ${psd_source_interfaces}
  ${psd_source_parser}
  ${psd_source_platform}
  ${psd_source_sections}
  ${psd_source_types}
  ${psd_source_util}
  ${psd_source_zip}
  ${psd_source_}
  ${psd_source_support}
)

set(STATIC_BUILD FALSE)

if (manual)
    if (${STATIC_BUILD})
        add_library(Psd STATIC ${psd_source})
    else()
        add_library(Psd SHARED ${psd_source})
    endif()
else ()
    add_library(Psd SHARED ${psd_source})
endif()

source_group("Source Files/Exporter" FILES ${psd_source_exporter})
source_group("Source Files/ImageUtil" FILES ${psd_source_image_util})
source_group("Source Files/Interfaces" FILES ${psd_source_interfaces})
source_group("Source Files/Parser" FILES ${psd_source_parser})
source_group("Source Files/Platform" FILES ${psd_source_platform})
source_group("Source Files/Sections" FILES ${psd_source_sections})
source_group("Source Files/Types" FILES ${psd_source_types})
source_group("Source Files/Util" FILES ${psd_source_util})
source_group("Source Files/Zip" FILES ${psd_source_zip})
source_group("Source Files" FILES ${psd_source_})

if(manual)
    file(REMOVE ./include)
    file(MAKE_DIRECTORY ./include)

    file(GLOB HEADER_FILES "*.h")

    foreach (header ${HEADER_FILES})
        file(COPY ${header} DESTINATION ${CMAKE_SOURCE_DIR}/include)
    endforeach ()
else()
    file(REMOVE ${LIBPATH_SUB}/psd/include)
    file(MAKE_DIRECTORY ${LIBPATH_SUB}/psd/include)

    file(GLOB HEADER_FILES "*.h")

    foreach (header ${HEADER_FILES})
        file(COPY ${header} DESTINATION ${LIBPATH_SUB}/psd/include)
    endforeach ()
endif ()

