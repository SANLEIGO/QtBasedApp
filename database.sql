-- 创建用户表
CREATE TABLE users (
    id INTEGER PRIMARY KEY AUTOINCREMENT,
    account VARCHAR(50) NOT NULL UNIQUE,
    password VARCHAR(50) NOT NULL,
    allow_sharing INTEGER DEFAULT 0,  -- 0表示不允许共享，1表示允许共享
    created_at DATETIME DEFAULT CURRENT_TIMESTAMP
);

-- 创建笔记表
CREATE TABLE text_files (
    id INTEGER PRIMARY KEY AUTOINCREMENT,
    user_account VARCHAR(50) NOT NULL,
    file_name VARCHAR(255) NOT NULL,
    content TEXT,
    uploaded_at DATETIME DEFAULT CURRENT_TIMESTAMP,
    FOREIGN KEY (user_account) REFERENCES users(account),
    UNIQUE(user_account, file_name)
);

-- 创建任务表
CREATE TABLE tasks (
    id INTEGER PRIMARY KEY AUTOINCREMENT,
    account VARCHAR(50) NOT NULL,
    task_name VARCHAR(255) NOT NULL,
    established_time DATETIME NOT NULL,
    dead_time DATETIME NOT NULL,
    completed INTEGER DEFAULT 0,  -- 0表示未完成，1表示已完成
    priority VARCHAR(20) DEFAULT '普通',  -- 优先级：高、中、普通、低
    notes TEXT,
    FOREIGN KEY (account) REFERENCES users(account)
);

-- 创建番茄钟会话表
CREATE TABLE pomodoro_sessions (
    id INTEGER PRIMARY KEY AUTOINCREMENT,
    task_id INTEGER,
    account VARCHAR(50) NOT NULL,
    start_time DATETIME NOT NULL,
    end_time DATETIME,
    duration INTEGER,  -- 持续时间（秒）
    is_completed INTEGER DEFAULT 0,  -- 0表示未完成，1表示已完成
    pause_count INTEGER DEFAULT 0,  -- 暂停次数
    notes TEXT,
    FOREIGN KEY (task_id) REFERENCES tasks(id),
    FOREIGN KEY (account) REFERENCES users(account)
);

-- 创建索引
CREATE INDEX idx_text_files_user ON text_files(user_account);
CREATE INDEX idx_tasks_account ON tasks(account);
CREATE INDEX idx_tasks_completed ON tasks(completed);
CREATE INDEX idx_pomodoro_account ON pomodoro_sessions(account);
CREATE INDEX idx_pomodoro_task ON pomodoro_sessions(task_id);

-- 添加示例数据（可选）
INSERT INTO users (account, password, allow_sharing) VALUES 
('admin', 'admin123', 1),
('user1', 'user123', 1),
('user2', 'user123', 0);

-- 添加触发器：更新任务完成状态时自动更新相关番茄钟会话
CREATE TRIGGER update_pomodoro_on_task_complete
AFTER UPDATE ON tasks
WHEN NEW.completed = 1
BEGIN
    UPDATE pomodoro_sessions 
    SET is_completed = 1 
    WHERE task_id = NEW.id AND is_completed = 0;
END; 