#include "convertpostfix.hpp"
#include "stack.hpp"

void piyavkin::convertPostfix(infix_t& infix, postfix_t& postfix)
{
  Stack< ConversionExpressionType > stack;
  for (auto it = infix.begin(); it != infix.end(); ++it)
  {
    Queue< Postfix > q;
    while (!it->empty())
    {
      if (it->front().getType() == detail::operand)
      {
        Postfix postfix_val(it->front().getOperand());
        it->pop();
        q.push(postfix_val);
      }
      else
      {
        if (it->front().getBraket() == '(')
        {
          ConversionExpressionType stack_val(it->front().getBraket(), detail::bracket);
          it->pop();
          stack.push(stack_val);
        }
        else if (it->front().getBraket() == ')')
        {
          while (stack.top().getBraket() != '(')
          {
            if (stack.empty())
            {
              throw std::logic_error("The parentheses are not placed correctly");
            }
            Postfix postfix_val(stack.top().getOperation());
            stack.pop();
            q.push(postfix_val);
          }
          stack.pop();
          it->pop();
        }
        else
        {
          while (!stack.empty() && !(it->front().getOperation() > stack.top().getOperation()))
          {
            if (stack.top().getType() == detail::bracket)
            {
              break;
            }
            Postfix postfix_val(stack.top().getOperation());
            stack.pop();
            q.push(postfix_val);
          }
          ConversionExpressionType stack_val(it->front().getOperation(), detail::operation);
          it->pop();
          stack.push(stack_val);
        }
      }
    }
    while (!stack.empty())
    {
      Postfix postfix_val(stack.top().getOperation());
      stack.pop();
      q.push(postfix_val);
    }
    postfix.push_back(q);
  }
}
