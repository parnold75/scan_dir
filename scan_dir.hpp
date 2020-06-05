#ifndef __SCAN_DIR_HPP__
#define __SCAN_DIR_HPP__

#pragma once

#include <string>
#include <functional>
#include <boost/filesystem.hpp>

typedef std::function<void(boost::filesystem::path)> dir_callback;
typedef std::function<void(boost::filesystem::path)> file_callback;
typedef std::function<void(boost::filesystem::path, boost::filesystem::filesystem_error)> error_callback;

/**
 * scan_dir returns by callback every directory and file that is within the specified path.
 * If an error occurs, e.g. permission denied, the error callback is called.
 * 
 * @param path The directory that will be scanned.
 * @param dir_callback For each found directory the callback function is called.
 * @param file_callback For each found file the callback function is called.
 * @param error_callback Is called when an error has occurred.
 */
void scan_dir(const boost::filesystem::path &path,
              const dir_callback &dir_callback,
              const file_callback &file_callback,
              const error_callback &error_callback);

#endif