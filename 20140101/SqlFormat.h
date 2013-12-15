#pragma once

namespace std {

	class SqlFormat
	{
	public:
		static const char * mValueCharacter = "'";
		static const char * mFieldCharacter = "`";
		static const char * mUpdateCharacter = "@";
		void _serialize<__t>(List<__t> nValue, string nName);
		void _serialize<__t>(__t nValue, string nName, SqlFieldId_ nSqlFieldId = SqlFieldId_.mNone_);
		void _runSerialize<__t>(__t nValue, string nName, SqlFieldId_ nSqlFieldId = SqlFieldId_.mNone_);
		void _serialize(bool nValue, string nName, SqlFieldId_ nSqlFieldId = SqlFieldId_.mNone_);
		void _serialize(sbyte nValue, string nName, SqlFieldId_ nSqlFieldId = SqlFieldId_.mNone_);
		void _serialize(List<sbyte> nValue, string nName);
		void _serialize(byte nValue, string nName, SqlFieldId_ nSqlFieldId = SqlFieldId_.mNone_);
		void _serialize(List<byte> nValue, string nName);
		void _serialize(byte[] nValue, string nName, SqlFieldId_ nSqlFieldId = SqlFieldId_.mNone_);
		void _serialize(short nValue, string nName, SqlFieldId_ nSqlFieldId = SqlFieldId_.mNone_);
		void _serialize(List<short> nValue, string nName);
		void _serialize(ushort nValue, string nName, SqlFieldId_ nSqlFieldId = SqlFieldId_.mNone_);
		void _serialize(List<ushort> nValue, string nName);
		void _serialize(int nValue, string nName, SqlFieldId_ nSqlFieldId = SqlFieldId_.mNone_);
		void _serialize(List<int> nValue, string nName);
		void _serialize(uint nValue, string nName, SqlFieldId_ nSqlFieldId = SqlFieldId_.mNone_);
		void _serialize(List<uint> nValue, string nName);
		void _serialize(long nValue, string nName, SqlFieldId_ nSqlFieldId = SqlFieldId_.mNone_);
		void _serialize(List<long> nValue, string nName);
		void _serialize(ulong nValue, string nName, SqlFieldId_ nSqlFieldId = SqlFieldId_.mNone_);
		void _serialize(List<ulong> nValue, string nName);
		void _serialize(string nValue, string nName, SqlFieldId_ nSqlFieldId = SqlFieldId_.mNone_);
		void _serialize(List<string> nValue, string nName);
		void _serialize(float nValue, string nName, SqlFieldId_ nSqlFieldId = SqlFieldId_.mNone_);
		void _serialize(List<float> nValue, string nName);
		void _serialize(double nValue, string nName, SqlFieldId_ nSqlFieldId = SqlFieldId_.mNone_);
		void _serialize(List<double> nValue, string nName);
		void _serialize(string nValue);

		template<class __t>
		void _runFormat(__t& nT);
	private:
		template<class __t>
		void _runDelete(__t& nT);
		template<class __t>
		void _runInsert(__t& nT);
		template<class __t>
		void _runSelect(__t& nT);
		template<class __t>
		void _runUpdate(__t& nT);
		template<class __t>
		void _runInsertUpdate(__t& nT);
		template<class __t>
		void _runUpdateInsert(__t& nT);
		template<class __t>
		void _runCreate(__t& nT);
	public:
		list<SqlParameter>& _getFields();
		const string& _sqlCommand();
		SqlFormat();
		~SqlFormat();

	private:
		list<SqlParameter> mFields;
		list<string> mUpdate;
		SqlDeal_ mSqlDeal;
		string mValue;
		string mName;
		bool mBeg;
		bool mEnd;
	};
	template<class __t>
	void SqlFormat::_runFormat(__t& nT)
	{
		SqlType_ sqlType_ = nT._sqlType();
		if (mSqlTypeDelete_ == sqlType_)
		{
			this._runDelete(nT);
		}
		else if (mSqlTypeInsert_ == sqlType_)
		{
			this._runInsert(nT);
		}
		else if (mSqlTypeSelect_ == sqlType_)
		{
			this._runSelect(nT);
		}
		else if (mSqlTypeUpdate_ == sqlType_)
		{
			this._runUpdate(nT);
		}
		else if (mSqlTypeInsertUpdate_ == sqlType_)
		{
			this._runInsertUpdate(nT);
		}
		else if (mSqlTypeUpdateInsert_ == sqlType_)
		{
			this._runUpdateInsert(nT);
		}
		else if (mSqlTypeCreate_ == sqlType_)
		{
			this._runCreate(nT);
		}
		else
		{
		}
	}
}
