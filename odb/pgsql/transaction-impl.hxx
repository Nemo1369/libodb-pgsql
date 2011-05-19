// file      : odb/pgsql/transaction-impl.hxx
// author    : Constantin Michael <constantin@codesynthesis.com>
// copyright : Copyright (c) 2009-2011 Code Synthesis Tools CC
// license   : GNU GPL v2; see accompanying LICENSE file

#ifndef ODB_PGSQL_TRANSACTION_IMPL_HXX
#define ODB_PGSQL_TRANSACTION_IMPL_HXX

#include <odb/pre.hxx>

#include <odb/transaction.hxx>

#include <odb/pgsql/version.hxx>
#include <odb/pgsql/forward.hxx>

#include <odb/details/shared-ptr.hxx>

#include <odb/pgsql/details/export.hxx>

namespace odb
{
  namespace pgsql
  {
    class LIBODB_PGSQL_EXPORT transaction_impl: public odb::transaction_impl
    {
    protected:
      friend class database;
      friend class transaction;

      typedef pgsql::database database_type;
      typedef pgsql::connection connection_type;

      transaction_impl (database_type&);

      virtual
      ~transaction_impl ();

      virtual void
      commit ();

      virtual void
      rollback ();

      connection_type&
      connection ();

    private:
      details::shared_ptr<connection_type> connection_;
    };
  }
}

#include <odb/pgsql/transaction-impl.ixx>

#include <odb/post.hxx>

#endif // ODB_PGSQL_TRANSACTION_IMPL_HXX