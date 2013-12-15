#pragma once

namespace std {

	enum SqlField_ : short
	{
		mSqlFieldNone_,
		mSqlFieldBool_,
		mSqlFieldI8_,
		mSqlFieldU8_,
		mSqlFieldI16_,
		mSqlFieldU16_,
		mSqlFieldI32_,
		mSqlFieldU32_,
		mSqlFieldI64_,
		mSqlFieldU64_,
		mSqlFieldString_,
		mSqlFieldFloat_,
		mSqlFieldDouble_,
		mSqlFieldBytes_
	};
}
