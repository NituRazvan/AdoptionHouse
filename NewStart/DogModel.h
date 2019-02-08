#pragma once
#include <QObject>
#include <QAbstractTableModel>
#include "FileAdoptionList.h"
#include <functional>
class DogModel : public QAbstractTableModel
{
private:
	FileAdoptionList * adoptionList;
public:
	//std::function <void(void)>updateBarChart;
	DogModel();
	DogModel(FileAdoptionList * adoptionList);
	~DogModel();
	int rowCount(const QModelIndex &parent = QModelIndex()) const;
	int columnCount(const QModelIndex &/*parent*/) const;
	QVariant data(const QModelIndex& index, int role = Qt::DisplayRole) const;
	QVariant headerData(int section, Qt::Orientation orientation, int role) const;

	// repository
	FileAdoptionList* getAdoptionList() { return adoptionList; };
	bool addDog(Dog d);
	Qt::ItemFlags flags(const QModelIndex & index) const override;
};