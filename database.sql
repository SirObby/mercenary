CREATE TABLE Actor (
    id SERIAL PRIMARY KEY,
    type VARCHAR(50) NOT NULL,
    preferred_username VARCHAR(50) UNIQUE NOT NULL,
    name VARCHAR(100),
    summary TEXT,
    inbox VARCHAR(255) NOT NULL,
    outbox VARCHAR(255) NOT NULL,
    created_at TIMESTAMP DEFAULT CURRENT_TIMESTAMP,
    updated_at TIMESTAMP DEFAULT CURRENT_TIMESTAMP
);

CREATE TABLE Followers (
    id SERIAL PRIMARY KEY,
    actor_id INTEGER NOT NULL,
    follower_id INTEGER NOT NULL,
    FOREIGN KEY (actor_id) REFERENCES Actor(id),
    FOREIGN KEY (follower_id) REFERENCES Actor(id)
);

CREATE TABLE Following (
    id SERIAL PRIMARY KEY,
    actor_id INTEGER NOT NULL,
    following_id INTEGER NOT NULL,
    FOREIGN KEY (actor_id) REFERENCES Actor(id),
    FOREIGN KEY (following_id) REFERENCES Actor(id)
);

CREATE TABLE Activity (
    id SERIAL PRIMARY KEY,
    type VARCHAR(50) NOT NULL,
    actor_id INTEGER NOT NULL,
    object TEXT NOT NULL,
    target TEXT,
    published TIMESTAMP DEFAULT CURRENT_TIMESTAMP,
    updated_at TIMESTAMP DEFAULT CURRENT_TIMESTAMP,
    FOREIGN KEY (actor_id) REFERENCES Actor(id)
);