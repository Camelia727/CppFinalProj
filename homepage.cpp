#include "homepage.h"
#include "./ui_homepage.h"

HomePage::HomePage(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::HomePage)
    , shopOn(false)
    , history(new History)
    , player(new QMediaPlayer(this))
    , audio(new QAudioOutput(this))
{
    ui->setupUi(this);

    setFixedSize(QSize(1000, 600));

    background.load(":/pics/pics/homepage.png");
    role_page = new RolePage(this);
    role_page->hide();
    game_page = nullptr;
    detail_page = new DetailPage(this);
    detail_page->hide();
    loadHistory();

    player->setAudioOutput(audio);
    player->setSource(QUrl("qrc:/music/music/homemusic.mp3"));
    audio->setVolume(30);
    player->play();

    connect(ui->gamebtn, &gameBtn::game_clicked, this, &HomePage::openRole);
    connect(ui->shopbtn, &shopBtn::shop_clicked, this, &HomePage::openShop);
    connect(ui->savebtn, &saveBtn::save_clicked, this, &HomePage::openSave);
    connect(ui->detailbtn, &detailBtn::detail_clicked, this, &HomePage::openDetail);
    connect(role_page, &RolePage::gameOpen, this, &HomePage::openGame);

}

HomePage::~HomePage()
{
    saveHistory();
    delete history;
    history = nullptr;
    delete role_page;
    role_page = nullptr;
    if (game_page)
    {
        delete game_page;
        game_page = nullptr;
    }
    delete ui;
}

void HomePage::saveHistory() const
{
    // 获取当前工作目录
    QDir currentDir = QDir::current();
    // 构建文件名
    QString fileName = currentDir.filePath("historyfile.txt");

    // 创建QFile对象
    QFile file(fileName);

    // 检查文件是否存在
    if (!file.exists()) {
        if (!file.open(QIODevice::WriteOnly | QIODevice::Text)) {
            qWarning() << "Could not open file for writing:" << file.errorString();
            return;
        }
        QTextStream out(&file);
        out << history->getGamecount() << " " << history->getMaxrounds() << " " << history->getCoins() << "\n";
        for (int i = 0; i < 5; i++)
            out << history->getbuff(static_cast<BUFFS>(i)) << " ";
    } else {
        if (!file.open(QIODevice::WriteOnly | QIODevice::Text | QIODevice::Truncate)) {
            qWarning() << "Could not open file for writing:" << file.errorString();
            return;
        }
        QTextStream out(&file);
        out << history->getGamecount() << " " << history->getMaxrounds() << " " << history->getCoins() << "\n";
        for (int i = 0; i < 6; i++)
            out << history->getbuff(static_cast<BUFFS>(i)) << " ";
    }

    // 关闭文件
    file.close();
}

void HomePage::loadHistory() const
{
    // 获取当前工作目录
    QDir currentDir = QDir::current();
    // 构建文件名
    QString fileName = currentDir.filePath("historyfile.txt");


    // 创建QFile对象并打开文件
    QFile file(fileName);
    if (!file.exists()){
        return;
    }

    if (!file.open(QIODevice::ReadOnly | QIODevice::Text)) {
        // 如果文件打开失败，打印错误信息
        qDebug() << "Cannot open file:" << fileName << "Error:" << file.errorString();
        return;
    }

    // 创建QTextStream对象，与QFile对象关联
    QTextStream in(&file);

    // 读取第一行的三个数字
    QString firstLine = in.readLine().trimmed();
    QStringList firstLineNumbers = firstLine.split(' ', Qt::SkipEmptyParts);
    if (firstLineNumbers.size() != 3) {
        qDebug() << "Invalid number of values in the first line.";
        file.close();
        return;
    }

    bool ok;
    int num1 = firstLineNumbers[0].toInt(&ok);
    int num2 = firstLineNumbers[1].toInt(&ok);
    int num3 = firstLineNumbers[2].toInt(&ok);
    if (!ok) {
        qDebug() << "Invalid numbers in the first line.";
        file.close();
        return;
    }
    history->setGamecount(std::max(num1, 0));
    history->setMaxrounds(std::max(num2, 0));
    history->setCoins(std::max(num3, 0));

    // 读取第二行的六个数字
    QString secondLine = in.readLine().trimmed();
    QStringList secondLineNumbers = secondLine.split(' ', Qt::SkipEmptyParts);
    if (secondLineNumbers.size() != 6) {
        qDebug() << "Invalid number of values in the second line.";
        file.close();
        return;
    }

    int nums[6];
    for (int i = 0; i < 6; ++i) {
        nums[i] = secondLineNumbers[i].toInt(&ok);
        if (!ok) {
            qDebug() << "Invalid numbers in the second line.";
            file.close();
            return;
        }
    }
    for (int i = 0; i < 6; ++i) {
        history->setBuffs(i, std::min(5, nums[i]));
    }

    // 关闭文件
    file.close();
}

void HomePage::clearHistory() const
{

}

void HomePage::closeEvent(QCloseEvent *event)
{

}

void HomePage::paintEvent(QPaintEvent *event)
{
    QPainter painter(this);
    painter.drawPixmap(this->rect(), background);
}

void HomePage::openRole()
{
    if (shopOn) {
        QMessageBox msg;
        msg.setText("请先退出商店再进行冒险哦~");
        msg.exec();
    }
    else{
        role_page->show();
    }
}

void HomePage::openGame(QString name)
{
    if (game_page){
        delete game_page;
        game_page = nullptr;
    }
    game_page = new GamePage(history, name);
    connect(game_page, &GamePage::gameend, this, &HomePage::gameEnd);
    game_page->show();
    hide();
    player->stop();
}

void HomePage::openDetail()
{
    detail_page->show();
}

void HomePage::openSave()
{
    saveHistory();
}

void HomePage::openShop()
{
    if (shopOn){
        QMessageBox msg;
        msg.setText("这里只有一家商店啦！");
        msg.exec();
    }
    else
    {
        ShopPage* shop_page = new ShopPage(history);
        if (shop_page != nullptr) {
            shopOn = true;
            connect(shop_page, &ShopPage::buyBuff, this, &HomePage::buyBuff);
            connect(shop_page, &ShopPage::shopClosed, this, &HomePage::closeShop);
            shop_page->show();
            hide();
        }
    }
}

void HomePage::closeShop()
{
    shopOn = false;
    show();
}

void HomePage::buyBuff(int buff, int coin)
{
    history->spendCoins(coin);
    history->gainBuff(static_cast<BUFFS>(buff));
}

void HomePage::gameEnd(int rounds)
{
    show();
    player->play();
    history->HistoryUpdate(rounds);
    saveHistory();
    disconnect(game_page, &GamePage::gameend, this, &HomePage::gameEnd);
    delete game_page;
    game_page = nullptr;
}
