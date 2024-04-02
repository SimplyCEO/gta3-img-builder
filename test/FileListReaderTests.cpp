#include <gtest/gtest.h>
#include "FileListReader.h"
#include "Exceptions.h"

TEST(ShouldFailIfFilesListIsNotFound, FileListReaderTests)
{
  EXPECT_THROW({
      FileListReader::Read("non_existing");
  }, CouldNotReadFilesList);
}

TEST(ShouldReadValidFilesList, FileListReaderTests)
{
  const auto& files = FileListReader::Read("test_files_list");
  const std::vector<std::filesystem::path> expected_files = {
    {"testfile1"},
    {"testfile2"},
    {"testfile3"}
  };

  EXPECT_EQ(expected_files, files);
}

TEST(ShouldFailIfFilesListContainsConflictingFilenames, FileListReaderTests)
{
  EXPECT_THROW({
      FileListReader::Read("test_conflicting_filenames_list");
  }, ConflictingFilenames);
}
