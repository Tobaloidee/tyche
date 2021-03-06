﻿CREATE TABLE [dbo].[BlockedIPs]
(
	[Id]		INT				IDENTITY(1,1) NOT NULL,	
	[IPAddress]	VARCHAR(255)	NOT NULL,
	[StartDate]	DATETIME		NOT NULL,
	[EndDate]	DATETIME		NOT NULL,
	[ReasonId]	INT				NULL

	CONSTRAINT [PK_BLOCKED_IP] PRIMARY KEY ([Id]),
	CONSTRAINT [FK_BLOCKED_IP_REASON_ID] FOREIGN KEY ([ReasonId]) REFERENCES [dbo].[BlockReasons]([Id])
		ON DELETE CASCADE	
)