/*Boost Software License - Version 1.0 - August 17th, 2003

Permission is hereby granted, free of charge, to any person or organization
obtaining a copy of the software and accompanying documentation covered by
this license (the "Software") to use, reproduce, display, distribute,
execute, and transmit the Software, and to prepare derivative works of the
Software, and to permit third-parties to whom the Software is furnished to
do so, all subject to the following:

The copyright notices in the Software and this entire statement, including
the above license grant, this restriction and the following disclaimer,
must be included in all copies of the Software, in whole or in part, and
all derivative works of the Software, unless such copies or derivative
works are solely in the form of machine-executable object code generated by
a source language processor.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE, TITLE AND NON-INFRINGEMENT. IN NO EVENT
SHALL THE COPYRIGHT HOLDERS OR ANYONE DISTRIBUTING THE SOFTWARE BE LIABLE
FOR ANY DAMAGES OR OTHER LIABILITY, WHETHER IN CONTRACT, TORT OR OTHERWISE,
ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER
DEALINGS IN THE SOFTWARE.*/
#include <cstdio>
#include <cstdlib>
#include <cstring>

class message
{
public:
  enum { header_size_ = 4 };
  enum { max_size = 512 };

  message()
    : msg_length_(0)
  {
  }

  const char* data() const
  {
    return data_;
  }

  char* data()
  {
    return data_;
  }

  std::size_t length() const
  {
    return header_size_ + msg_length_;
  }

  const char* body() const
  {
    return data_ + header_size_;
  }

  char* body()
  {
    return data_ + header_size_;
  }

  std::size_t body_length() const
  {
    return msg_length_;
  }

  void body_length(std::size_t new_length)
  {
    msg_length_ = new_length;
    if (msg_length_ > max_size)
      msg_length_ = max_size;
  }

  bool decode_header()
  {
    char header[header_size_ + 1] = "";
    std::strncat(header, data_, header_size_);
    msg_length_ = std::atoi(header);
    if (msg_length_ > max_size)
    {
      msg_length_ = 0;
      return false;
    }
    return true;
  }

  void encode_header()
  {
    char header[header_size_ + 1] = "";
    std::sprintf(header, "%4d", static_cast<int>(msg_length_));
    std::memcpy(data_, header, header_size_);
  }

private:
  char data_[header_size_ + max_size];
  std::size_t msg_length_;
};
