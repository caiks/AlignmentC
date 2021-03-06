﻿#ifndef ALIGNMENTAESON_H
#define ALIGNMENTAESON_H

#include "Alignment.h"

namespace Alignment
{
	// stringsVariable :: String -> Variable
	Variable stringsVariable(const std::string&);

	typedef std::map<std::string, VarPtr> StrVarPtrMap;

	// stringsVariable :: String -> Variable
	VarPtr stringsVariable(const std::string&, StrVarPtrMap&);

	// stringsValue :: String -> Value
	Value stringsValue(const std::string&);

	// stringsRational :: String -> Rational
	Rational stringsRational(const std::string&);

	// rationalsString :: Rational -> String
	std::string rationalsString(const Rational&);

	// systemsPersistent :: System -> SystemPersistent
	void systemsPersistent(const System&, std::ostream&);

	// systemsPersistentSorted :: System -> SystemPersistent
	void systemsPersistentSorted(const System&, std::ostream&);

	// persistentsSystem :: SystemPersistent -> Maybe System
	std::unique_ptr<System> persistentsSystem(std::istream&);

	// persistentsSystem :: SystemPersistent -> Maybe System
	std::unique_ptr<System> persistentsSystem(std::istream&, StrVarPtrMap&);

	// historiesPersistent :: History -> HistoryPersistent
	void historiesPersistent(const History&, std::ostream&);

	// historiesPersistentPretty :: History -> HistoryPersistent
	void historiesPersistentPretty(int r, const History&, std::ostream&);

	// persistentsHistory :: HistoryPersistent -> Maybe History
	std::unique_ptr<History> persistentsHistory(std::istream&);

	// persistentsHistory :: HistoryPersistent -> Maybe History
	std::unique_ptr<History> persistentsHistory(std::istream&, StrVarPtrMap&);

	// transformsPersistent :: Transform -> TransformPersistent
	void transformsPersistent(const Transform&, std::ostream&);

	// transformsPersistentPretty :: Transform -> TransformPersistent
	void transformsPersistentPretty(int r, const Transform&, std::ostream&);

	// persistentsTransform :: TransformPersistent -> Maybe Transform
	std::unique_ptr<Transform> persistentsTransform(std::istream&);

	// persistentsTransform :: TransformPersistent -> Maybe Transform
	std::unique_ptr<Transform> persistentsTransform(std::istream&, StrVarPtrMap&);

	// fudsPersistent :: Fud -> FudPersistent
	void fudsPersistent(const Fud&, std::ostream&);

	// fudsPersistentPretty :: Fud -> FudPersistent
	void fudsPersistentPretty(int r, const Fud&, std::ostream&);

	// persistentsFud :: FudPersistent -> Maybe Fud
	std::unique_ptr<Fud> persistentsFud(std::istream&);

	// persistentsFud :: FudPersistent -> Maybe Fud
	std::unique_ptr<Fud> persistentsFud(std::istream&, StrVarPtrMap&);

	// decompFudsPersistent :: DecompFud -> DecompFudPersistent
	void decompFudsPersistent(const DecompFud&, std::ostream&);

	// decompFudsPersistentPretty :: DecompFud -> DecompFudPersistent
	void decompFudsPersistentPretty(const DecompFud&, std::ostream&);

	// persistentsDecompFud :: DecompFudPersistent -> Maybe DecompFud
	std::unique_ptr<DecompFud> persistentsDecompFud(std::istream&);

	// persistentsDecompFud :: DecompFudPersistent -> Maybe DecompFud
	std::unique_ptr<DecompFud> persistentsDecompFud(std::istream&, StrVarPtrMap&);

}



#endif