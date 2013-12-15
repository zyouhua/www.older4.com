#pragma once

namespace std {

	enum SqlType_ : unsigned short
	{
		mSqlTypeSelect_,
		mSqlTypeInsert_,
		mSqlTypeUpdate_,
		mSqlTypeDelete_,
		mSqlTypeInsertUpdate_,
		mSqlTypeCreate_,
		mSqlTypeUpdateInsert_,
	};

}
