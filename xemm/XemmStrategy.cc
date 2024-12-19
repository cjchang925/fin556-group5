/*================================================================================
*     Source: ../RCM/StrategyStudio/examples/strategies/SimpleMomentumStrategy/SimpleMomentumStrategy.cpp
*     Last Update: 2013/6/1 13:55:14
*     Contents:
*     Distribution:
*
*
*     Copyright (c) RCM-X, 2011 - 2013.
*     All rights reserved.
*
*     This software is part of Licensed material, which is the property of RCM-X ("Company"),
*     and constitutes Confidential Information of the Company.
*     Unauthorized use, modification, duplication or distribution is strictly prohibited by Federal law.
*     No title to or ownership of this software is hereby transferred.
*
*     The software is provided "as is", and in no event shall the Company or any of its affiliates or successors be liable for any
*     damages, including any lost profits or other incidental or consequential damages relating to the use of this software.
*     The Company makes no representations or warranties, express or implied, with regards to this software.
/*================================================================================*/

#ifdef _WIN32
#include "stdafx.h"
#endif

#include "XemmStrategy.hh"

using namespace RCM::StrategyStudio;
using namespace RCM::StrategyStudio::MarketModels;
using namespace RCM::StrategyStudio::Utilities;

XemmStrategy::XemmStrategy(StrategyID strategyID, const std::string& strategyName, const std::string& groupName):
        Strategy(strategyID, strategyName, groupName)
{
}

XemmStrategy::~XemmStrategy()
{
}

void XemmStrategy::OnResetStrategyState()
{
}

void XemmStrategy::DefineStrategyParams()
{
}

void XemmStrategy::DefineStrategyCommands()
{
}

void XemmStrategy::RegisterForStrategyEvents(StrategyEventRegister* eventRegister, DateType currDate)
{

}
void XemmStrategy::OnTrade(const TradeDataEventMsg& msg)
{
   
}

void XemmStrategy::OnTopQuote(const QuoteEventMsg& msg)
{
}

void XemmStrategy::SendBuyOrder(const Instrument* instrument, int quantity)
{
    OrderParams params(*instrument,
                       quantity,
                       (instrument->top_quote().ask() != 0) ? instrument->top_quote().ask() : instrument->last_trade().price(),
                       (instrument->type() == INSTRUMENT_TYPE_EQUITY) ? MARKET_CENTER_ID_NASDAQ : ((instrument->type() == INSTRUMENT_TYPE_OPTION) ? MARKET_CENTER_ID_CBOE_OPTIONS : MARKET_CENTER_ID_CME_GLOBEX),
                       ORDER_SIDE_BUY,
                       ORDER_TIF_DAY,
                       ORDER_TYPE_MARKET);

    trade_actions()->SendNewOrder(params);
}

void XemmStrategy::SendSellOrder(const Instrument* instrument, int quantity)
{
    OrderParams params(*instrument,
                       quantity,
                       (instrument->top_quote().bid() != 0) ? instrument->top_quote().bid() : instrument->last_trade().price(),
                       (instrument->type() == INSTRUMENT_TYPE_EQUITY) ? MARKET_CENTER_ID_NASDAQ : ((instrument->type() == INSTRUMENT_TYPE_OPTION) ? MARKET_CENTER_ID_CBOE_OPTIONS : MARKET_CENTER_ID_CME_GLOBEX),
                       ORDER_SIDE_SELL,
                       ORDER_TIF_DAY,
                       ORDER_TYPE_MARKET);

    trade_actions()->SendNewOrder(params);
}

void XemmStrategy::OnQuote(const QuoteEventMsg& msg)
{
}

void XemmStrategy::OnDepth(const MarketDepthEventMsg& msg)
{
}

void XemmStrategy::OnBar(const BarEventMsg& msg)
{
    std::cout << "BOOBS; " << std::endl;
}

void XemmStrategy::OnOrderUpdate(const OrderUpdateEventMsg& msg)
{
}

void XemmStrategy::OnStrategyCommand(const StrategyCommandEventMsg& msg)
{
}

void XemmStrategy::OnParamChanged(StrategyParam& param)
{
}
