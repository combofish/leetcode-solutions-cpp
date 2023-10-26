
select sum(amount) as 'sum(amount)'
from (
select amount from AccoCurrent_202211 where id = '1001'
union ALL
select amount from AccoCurrent_202212 where id = '1001'
) as combine_amounts;