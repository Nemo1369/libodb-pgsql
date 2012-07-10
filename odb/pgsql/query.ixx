// file      : odb/pgsql/query.ixx
// copyright : Copyright (c) 2009-2012 Code Synthesis Tools CC
// license   : GNU GPL v2; see accompanying LICENSE file

namespace odb
{
  namespace pgsql
  {
    template <typename T, database_type_id ID>
    inline void query::
    append (val_bind<T> v, const char* conv)
    {
      add (
        details::shared_ptr<query_param> (
          new (details::shared) query_param_impl<T, ID> (v)),
        conv);
    }

    template <typename T, database_type_id ID>
    inline void query::
    append (ref_bind<T> r, const char* conv)
    {
      add (
        details::shared_ptr<query_param> (
          new (details::shared) query_param_impl<T, ID> (r)),
        conv);
    }
  }
}
