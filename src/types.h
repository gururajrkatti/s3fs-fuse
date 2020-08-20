/*
 * s3fs - FUSE-based file system backed by Amazon S3
 *
 * Copyright(C) 2007 Randy Rizun <rrizun@gmail.com>
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
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301, USA.
 */

#ifndef S3FS_TYPES_H_
#define S3FS_TYPES_H_

class storage_class_t{
  public:
    enum Value{
      STANDARD,
      STANDARD_IA,
      ONEZONE_IA,
      REDUCED_REDUNDANCY,
      INTELLIGENT_TIERING,
      GLACIER,
      UNKNOWN
    };

    // cppcheck-suppress noExplicitConstructor
    storage_class_t(Value value) : value_(value) {}

    operator Value() const { return value_; }

    const char* str() const {
      switch(value_){
      case STANDARD:
        return "STANDARD";
      case STANDARD_IA:
        return "STANDARD_IA";
      case ONEZONE_IA:
        return "ONEZONE_IA";
      case REDUCED_REDUNDANCY:
        return "REDUCED_REDUNDANCY";
      case INTELLIGENT_TIERING:
        return "INTELLIGENT_TIERING";
      case GLACIER:
        return "GLACIER";
      case UNKNOWN:
        return NULL;
      }
      abort();
    }

    static storage_class_t from_str(const char* str) {
      if(0 == strcmp(str, "standard")){
        return STANDARD;
      }else if(0 == strcmp(str, "standard_ia")){
        return STANDARD_IA;
      }else if(0 == strcmp(str, "onezone_ia")){
        return ONEZONE_IA;
      }else if(0 == strcmp(str, "reduced_redundancy")){
        return REDUCED_REDUNDANCY;
      }else if(0 == strcmp(str, "intelligent_tiering")){
        return INTELLIGENT_TIERING;
      }else if(0 == strcmp(str, "glacier")){
        return GLACIER;
      }else{
        return UNKNOWN;
      }
    }

  private:
    explicit operator bool();
    Value value_;
};

class acl_t{
  public:
    enum Value{
      PRIVATE,
      PUBLIC_READ,
      PUBLIC_READ_WRITE,
      AWS_EXEC_READ,
      AUTHENTICATED_READ,
      BUCKET_OWNER_READ,
      BUCKET_OWNER_FULL_CONTROL,
      LOG_DELIVERY_WRITE,
      UNKNOWN
    };

    // cppcheck-suppress noExplicitConstructor
    acl_t(Value value) : value_(value) {}

    operator Value() const { return value_; }

    const char* str() const {
      switch(value_){
      case PRIVATE:
        return "private";
      case PUBLIC_READ:
        return "public-read";
      case PUBLIC_READ_WRITE:
        return "public-read-write";
      case AWS_EXEC_READ:
        return "aws-exec-read";
      case AUTHENTICATED_READ:
        return "authenticated-read";
      case BUCKET_OWNER_READ:
        return "bucket-owner-read";
      case BUCKET_OWNER_FULL_CONTROL:
        return "bucket-owner-full-control";
      case LOG_DELIVERY_WRITE:
        return "log-delivery-write";
      case UNKNOWN:
        return NULL;
      }
      abort();
    }

    static acl_t from_str(const char *acl) {
      if(0 == strcmp(acl, "private")){
        return PRIVATE;
      }else if(0 == strcmp(acl, "public-read")){
        return PUBLIC_READ;
      }else if(0 == strcmp(acl, "public-read-write")){
        return PUBLIC_READ_WRITE;
      }else if(0 == strcmp(acl, "aws-exec-read")){
        return AWS_EXEC_READ;
      }else if(0 == strcmp(acl, "authenticated-read")){
        return AUTHENTICATED_READ;
      }else if(0 == strcmp(acl, "bucket-owner-read")){
        return BUCKET_OWNER_READ;
      }else if(0 == strcmp(acl, "bucket-owner-full-control")){
        return BUCKET_OWNER_FULL_CONTROL;
      }else if(0 == strcmp(acl, "log-delivery-write")){
        return LOG_DELIVERY_WRITE;
      }else{
        return UNKNOWN;
      }
    }

  private:
    explicit operator bool();
    Value value_;
};

class sse_type_t{
  public:
    enum Value{
      SSE_DISABLE = 0,      // not use server side encrypting
      SSE_S3,               // server side encrypting by S3 key
      SSE_C,                // server side encrypting by custom key
      SSE_KMS               // server side encrypting by kms id
    };

    // cppcheck-suppress noExplicitConstructor
    sse_type_t(Value value) : value_(value) {}

    operator Value() const { return value_; }

  private:
    explicit operator bool();
    Value value_;
};

#endif // S3FS_TYPES_H_

/*
* Local variables:
* tab-width: 2
* c-basic-offset: 2
* End:
* vim600: expandtab sw=2 ts=2 fdm=marker
* vim<600: expandtab sw=2 ts=2
*/
