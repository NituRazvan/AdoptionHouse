#include "DogModel.h"
#include <qmessagebox.h>
#include "Utils.h"
DogModel::DogModel() :QAbstractTableModel()
{

}
DogModel::DogModel(FileAdoptionList * adoptionList)
{
	this->adoptionList = adoptionList;
}
DogModel::~DogModel()
{
	delete adoptionList;
}
int DogModel::rowCount(const QModelIndex & parent) const
{
	return adoptionList->getSize();

}
int DogModel::columnCount(const QModelIndex &) const
{
	return 4;
}
QVariant DogModel::data(const QModelIndex & index, int role) const
{
	int row = index.row();
	int column = index.column();

	std::vector<Dog> dogs = adoptionList->getDogs();

	if (row == dogs.size())
	{
		return QVariant();
	}

	Dog d = dogs[row];
	if (role == Qt::DisplayRole || role == Qt::EditRole)
	{
		switch (column)
		{
		case 0:
			return QString::fromStdString(d.getBreed());
		case 1:
			return QString::fromStdString(d.getName());
		case 2:
			return QString::fromStdString((std::to_string(d.getAge())));
		case 3:
			return QString::fromStdString(d.getPhoto());
		default:
			break;
		}
	}
	if (role == Qt::FontRole)
	{
		QFont font("Times", 15, 10, true);
		font.setItalic(false);
		return font;
	}
	if (role == Qt::BackgroundRole)
	{
		if (row % 2 == 1)
		{
			return QBrush{ QColor{ 0, 250, 154 } };
		}
	}

	return QVariant{};

}
QVariant DogModel::headerData(int section, Qt::Orientation orientation, int role) const
{
	{
		if (role != Qt::DisplayRole)
			return QVariant();

		if (orientation == Qt::Horizontal) {
			switch (section) {
			case 0:
				return tr("Breed");
			case 1:
				return tr("Name");
			case 2:
				return tr("Age");
			case 3:
				return tr("Source of photo");
			default:
				return QVariant();
			}
		}
		return QVariant();
	}
}

bool DogModel::addDog(Dog d)
{
	beginInsertRows(QModelIndex(), 0, 0);
	int x = adoptionList->addL(d);
	if (x == 1)
		endInsertRows();
	return true;
}

Qt::ItemFlags DogModel::flags(const QModelIndex & index) const
{
	return Qt::ItemIsSelectable | Qt::ItemIsEditable | Qt::ItemIsEnabled;
}

